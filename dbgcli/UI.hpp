//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: UI.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef _DBGD_DBGCLI_UI_BASE_CLASSES_HPP
#define _DBGD_DBGCLI_UI_BASE_CLASSES_HPP

// clang-format off
#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/frame.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/splitter.h>
#include <wx/stc/stc.h>
#include <wx/notebook.h>
#include <wx/imaglist.h>
#include <wx/toolbar.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

#ifdef WXC_FROM_DIP
#undef WXC_FROM_DIP
#endif
#if wxVERSION_NUMBER >= 3100
#define WXC_FROM_DIP(x) wxWindow::FromDIP(x, NULL)
#else
#define WXC_FROM_DIP(x) x
#endif

// clang-format on

class MainFrameBase : public wxFrame
{
protected:
    wxPanel* m_panel2;
    wxSplitterWindow* m_splitter4;
    wxPanel* m_splitterPage6;
    wxStyledTextCtrl* m_stcText;
    wxPanel* m_splitterPage8;
    wxNotebook* m_notebook17;
    wxPanel* m_panel18;
    wxStyledTextCtrl* m_stcStack;
    wxPanel* m_panel19;
    wxStyledTextCtrl* m_stcThreads;
    wxPanel* m_panel27;
    wxStyledTextCtrl* m_stcLog;
    wxPanel* m_panel30;
    wxStyledTextCtrl* m_stcScopes;
    wxToolBar* m_toolbar12;

protected:
    virtual void OnConnect(wxCommandEvent& event) { event.Skip(); }
    virtual void OnConnectUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnNext(wxCommandEvent& event) { event.Skip(); }
    virtual void OnNextUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnStepIn(wxCommandEvent& event) { event.Skip(); }
    virtual void OnStepInUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnStepOut(wxCommandEvent& event) { event.Skip(); }
    virtual void OnStepOutUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnPause(wxCommandEvent& event) { event.Skip(); }
    virtual void OnPauseUI(wxUpdateUIEvent& event) { event.Skip(); }

public:
    wxStyledTextCtrl* GetStcText() { return m_stcText; }
    wxPanel* GetSplitterPage6() { return m_splitterPage6; }
    wxStyledTextCtrl* GetStcStack() { return m_stcStack; }
    wxPanel* GetPanel18() { return m_panel18; }
    wxStyledTextCtrl* GetStcThreads() { return m_stcThreads; }
    wxPanel* GetPanel19() { return m_panel19; }
    wxStyledTextCtrl* GetStcLog() { return m_stcLog; }
    wxPanel* GetPanel27() { return m_panel27; }
    wxStyledTextCtrl* GetStcScopes() { return m_stcScopes; }
    wxPanel* GetPanel30() { return m_panel30; }
    wxNotebook* GetNotebook17() { return m_notebook17; }
    wxPanel* GetSplitterPage8() { return m_splitterPage8; }
    wxSplitterWindow* GetSplitter4() { return m_splitter4; }
    wxPanel* GetPanel2() { return m_panel2; }
    wxToolBar* GetToolbar12() { return m_toolbar12; }
    MainFrameBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("DAP UI"),
                  const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(800, 600),
                  long style = wxDEFAULT_FRAME_STYLE);
    virtual ~MainFrameBase();
};

#endif
