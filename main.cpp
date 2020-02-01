#include "CommandLineParser.hpp"
#include "Driver.hpp"
#include "GDBMI.hpp"
#include "GdbHandler.hpp"
#include "dap/Exception.hpp"
#include "dap/JsonRPC.hpp"
#include "dap/Log.hpp"
#include "dap/Process.hpp"
#include "dap/ServerProtocol.hpp"
#include "dap/SocketBase.hpp"
#include "dap/SocketServer.hpp"
#include "dap/StringUtils.hpp"
#include "dap/dap.hpp"
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char** argv)
{
    // Parse the command line arguments (exit if needed)
    CommandLineParser parser;
    parser.Parse(argc, argv);

    GDBMI mi;
    auto breakpoints = mi.ParseBreakpoints(
        "body=[bkpt={number=\"1\",type=\"breakpoint\",disp=\"keep\",enabled=\"y\",addr="
        "\"0x0000000000401564\",func=\"main(int,char**)\",file=\"C:/Users/Eran/Documents/AmitTest/"
        "AmitTest/"
        "main.cpp\",fullname=\"C:\\Users\\Eran\\Documents\\AmitTest\\AmitTest\\main.cpp\",line=\"10\","
        "thread-groups=[\"i1\"],times=\"0\",original-location=\"main.cpp:10\"},bkpt={number=\"2\",type="
        "\"breakpoint\",disp=\"keep\",enabled=\"y\",addr=\"0x0000000000401564\",func=\"main(int,char**)"
        "\",file=\"C:/Users/Eran/Documents/AmitTest/AmitTest/"
        "main.cpp\",fullname=\"C:\\Users\\Eran\\Documents\\AmitTest\\AmitTest\\main.cpp\",line=\"12\","
        "thread-groups=[\"i1\"],times=\"0\",original-location=\"main.cpp:12\"}]}");

    // Open the log file
    dap::Log::OpenStdout(dap::Log::Developer);
    LOG_INFO() << "Started";

    try {
        // Initialize the dap library
        dap::Initialize();
        LOG_INFO() << "Listening on " << parser.GetConnectionString();

        dap::SocketServer socketServer;
        socketServer.Start(parser.GetConnectionString());
        LOG_INFO() << "Waiting for a new connection";

        dap::SocketBase::Ptr_t client = socketServer.WaitForNewConnection();
        LOG_INFO() << "Connection established successfully";

        // Construct a Driver with GDB handler
        GdbHandler::Ptr_t backend(new GdbHandler());
        Driver gdb(parser, backend);

        // We dont start the main loop until 'initialize' is completed
        // between gdbd and the client
        dap::ServerProtocol server(client);
        server.Initialize();

        // Prepare callbacks
        server.RegisterNetworkCallback([&gdb](dap::ProtocolMessage::Ptr_t message) {
            // Pass the message to gdb for processing
            gdb.ProcessNetworkMessage(message);
        });

        gdb.RegisterGdbOutputCallback([&server](dap::ProtocolMessage::Ptr_t message) {
            // Pass the message to the network server for processing
            server.ProcessGdbMessage(message);
        });

        // The main loop:
        // - Check for any input from GDB and send it over JSONRpc to the client
        // - Check for any request from the client and pass it to the gdb
        while(gdb.IsAlive()) {
            // If we got something from gdb, process it
            // by converting it to the proper dap message
            // and send it over
            gdb.Check();

            // Check if a request arrived from the client
            // If so, convert it back gdb commands and send it over to gdb
            server.Check();
        }
    } catch(dap::Exception& e) {
        LOG_ERROR() << "ERROR: " << e.What();
        return 1;
    }
    // We are done
    return 0;
}
