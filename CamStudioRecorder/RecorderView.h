#pragma once

#include "VideoWnd.h"     // for CVideoWnd
#include "FlashingWnd.h"  // for CFlashingWnd
#include "BasicMessageDlg.h" // for CBasicMessageDlg
#include "screen.h"
#include "MP4Converter.h"

#include <string>

#define TEMPFILETAGINDICATOR "~temp"

class CRecorderDoc;

class CRecorderView : public CView
{
protected: // create from serialization only
    CRecorderView();
    DECLARE_DYNCREATE(CRecorderView)

    // Attributes
public:
    CRecorderDoc *GetDocument();

    void SaveSettings();
    void LoadSettings();
    void DecideSaveSettings();

    // Operations
public:
    // Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CRecorderView)
public:
    virtual void OnDraw(CDC *pDC); // overridden to draw this view
    virtual BOOL PreCreateWindow(CREATESTRUCT &cs);

protected:
    virtual BOOL OnPreparePrinting(CPrintInfo *pInfo);
    virtual void OnBeginPrinting(CDC *pDC, CPrintInfo *pInfo);
    virtual void OnEndPrinting(CDC *pDC, CPrintInfo *pInfo);
    //}}AFX_VIRTUAL

    // Implementation
public:
    ~CRecorderView() override;

    bool GetRecordState();
    bool GetPausedState();

#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext &dc) const;
#endif

protected:
    //{{AFX_MSG(CRecorderView)
    afx_msg void OnRegionRubber();
    afx_msg void OnRegionPanregion();
    afx_msg void OnPaint();
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnDestroy();
    afx_msg void OnRecord();
    afx_msg void OnStop();
    afx_msg void OnUpdateRegionPanregion(CCmdUI *pCmdUI);
    afx_msg void OnUpdateRegionRubber(CCmdUI *pCmdUI);
    afx_msg void OnFileVideooptions();
    afx_msg void OnOptionsCursoroptions();
    afx_msg void OnOptionsAutopan();
    afx_msg void OnOptionsAtuopanspeed();
    afx_msg void OnUpdateOptionsAutopan(CCmdUI *pCmdUI);
    afx_msg void OnUpdateRecord(CCmdUI *pCmdUI);
    afx_msg void OnRegionFullscreen();
    afx_msg void OnUpdateRegionFullscreen(CCmdUI *pCmdUI);
    afx_msg void OnRegionSelectScreen();
    afx_msg void OnUpdateRegionSelectScreen(CCmdUI *pCmdUI);
    afx_msg void OnRegionAllScreens();
    afx_msg void OnUpdateRegionAllScreens(CCmdUI *pCmdUI);
    afx_msg void OnOptionsMinimizeonstart();
    afx_msg void OnUpdateOptionsMinimizeonstart(CCmdUI *pCmdUI);
    afx_msg void OnOptionsHideflashing();
    afx_msg void OnUpdateOptionsHideflashing(CCmdUI *pCmdUI);
    afx_msg void OnOptionsProgramoptionsPlayavi();
    afx_msg void OnUpdateOptionsProgramoptionsPlayavi(CCmdUI *pCmdUI);
    afx_msg void OnHelpWebsite();
    afx_msg void OnHelpHelp();
    afx_msg void OnPause();
    afx_msg void OnUpdatePause(CCmdUI *pCmdUI);
    afx_msg void OnUpdateStop(CCmdUI *pCmdUI);
    afx_msg void OnOptionsRecordaudio();
    afx_msg void OnUpdateOptionsRecordaudio(CCmdUI *pCmdUI);
    afx_msg void OnOptionsAudioformat();
    afx_msg void OnOptionsAudiospeakers();
    afx_msg void OnHelpFaq();
    afx_msg void OnOptionsKeyboardshortcuts();
    afx_msg void OnOptionsProgramoptionsSavesettingsonexit();
    afx_msg void OnUpdateOptionsProgramoptionsSavesettingsonexit(CCmdUI *pCmdUI);
    afx_msg void OnOptionsRecordingthreadpriorityNormal();
    afx_msg void OnOptionsRecordingthreadpriorityHighest();
    afx_msg void OnOptionsRecordingthreadpriorityAbovenormal();
    afx_msg void OnOptionsRecordingthreadpriorityTimecritical();
    afx_msg void OnUpdateOptionsRecordingthreadpriorityTimecritical(CCmdUI *pCmdUI);
    afx_msg void OnUpdateOptionsRecordingthreadpriorityNormal(CCmdUI *pCmdUI);
    afx_msg void OnUpdateOptionsRecordingthreadpriorityHighest(CCmdUI *pCmdUI);
    afx_msg void OnUpdateOptionsRecordingthreadpriorityAbovenormal(CCmdUI *pCmdUI);
    afx_msg void OnOptionsCapturetrans();
    afx_msg void OnUpdateOptionsCapturetrans(CCmdUI *pCmdUI);
    afx_msg void OnOptionsTempdirWindows();
    afx_msg void OnUpdateOptionsTempdirWindows(CCmdUI *pCmdUI);
    afx_msg void OnOptionsTempdirInstalled();
    afx_msg void OnUpdateOptionsTempdirInstalled(CCmdUI *pCmdUI);
    afx_msg void OnOptionsTempdirUser();
    afx_msg void OnUpdateOptionsTempdirUser(CCmdUI *pCmdUI);

    afx_msg void OnOptionsOutputDirWindows();
    afx_msg void OnUpdateOptionsOutputDirWindows(CCmdUI *pCmdUI);
    afx_msg void OnOptionsOutputDirInstalled();
    afx_msg void OnUpdateOptionsOutputDirInstalled(CCmdUI *pCmdUI);
    afx_msg void OnOptionsOutputDirUser();
    afx_msg void OnUpdateOptionsUser(CCmdUI *pCmdUI);

    afx_msg void OnOptionsRecordaudioDonotrecordaudio();
    afx_msg void OnUpdateOptionsRecordaudioDonotrecordaudio(CCmdUI *pCmdUI);
    afx_msg void OnOptionsRecordaudioRecordfromspeakers();
    afx_msg void OnUpdateOptionsRecordaudioRecordfromspeakers(CCmdUI *pCmdUI);
    afx_msg void OnOptionsRecordaudiomicrophone();
    afx_msg void OnUpdateOptionsRecordaudiomicrophone(CCmdUI *pCmdUI);
    afx_msg void OnOptionsProgramoptionsTroubleshoot();
    afx_msg void OnOptionsProgramoptionsCamstudioplay();
    afx_msg void OnUpdateOptionsProgramoptionsCamstudioplay(CCmdUI *pCmdUI);
    afx_msg void OnOptionsProgramoptionsDefaultplay();
    afx_msg void OnUpdateOptionsProgramoptionsDefaultplay(CCmdUI *pCmdUI);
    afx_msg void OnOptionsProgramoptionsNoplay();
    afx_msg void OnUpdateOptionsProgramoptionsNoplay(CCmdUI *pCmdUI);
    afx_msg void OnHelpDonations();
    afx_msg void OnOptionsUsePlayer20();
    afx_msg void OnUpdateUsePlayer20(CCmdUI *pCmdUI);
    afx_msg void OnViewScreenannotations();
    afx_msg void OnUpdateViewScreenannotations(CCmdUI *pCmdUI);
    afx_msg void OnViewVideoannotations();
    afx_msg void OnOptionsSynchronization();
    afx_msg void OnSetFocus(CWnd *pOldWnd);
    afx_msg void OnAVISWFMP4();
    afx_msg BOOL OnEraseBkgnd(CDC *pDC);
    afx_msg void OnOptionsNamingAutodate();
    afx_msg void OnUpdateOptionsNamingAutodate(CCmdUI *pCmdUI);
    afx_msg void OnOptionsNamingAsk();
    afx_msg void OnUpdateOptionsNamingAsk(CCmdUI *pCmdUI);
    afx_msg void OnOptionsProgramoptionsPresettime();
    afx_msg void OnUpdateOptionsLanguageEnglish(CCmdUI *pCmdUI);
    afx_msg void OnUpdateOptionsLanguageGerman(CCmdUI *pCmdUI);
    afx_msg void OnUpdateOptionsLanguageFilipino(CCmdUI *pCmdUI);
    afx_msg void OnOptionsLanguageEnglish();
    afx_msg void OnOptionsLanguageGerman();
    afx_msg void OnOptionsLanguageFilipino();
    afx_msg void OnRegionWindow();
    afx_msg void OnUpdateRegionWindow(CCmdUI *pCmdUI);
    afx_msg void OnCaptureChanged(CWnd *pWnd);
    afx_msg void OnAnnotationAddsystemtimestamp();
    afx_msg void OnUpdateAnnotationAddsystemtimestamp(CCmdUI *pCmdUI);

    afx_msg void OnCameraDelayInMilliSec();
    afx_msg void OnRecordDurationLimitInMilliSec();

    afx_msg void OnAnnotationAddcaption();
    afx_msg void OnUpdateAnnotationAddcaption(CCmdUI *pCmdUI);
    afx_msg void OnAnnotationAddwatermark();
    afx_msg void OnUpdateAnnotationAddwatermark(CCmdUI *pCmdUI);
    afx_msg void OnEffectsOptions();
    afx_msg void OnHelpCamstudioblog();
    afx_msg void OnBnClickedButtonlink();
    afx_msg void OnUpdateOptionsAudiooptionsAudiovideosynchronization(CCmdUI *pCmdUI);

    //}}AFX_MSG
    afx_msg LRESULT OnRecordStart(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnRecordInterrupted(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnRecordPaused(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnSaveCursor(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnUserGeneric(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnMM_WIM_DATA(WPARAM parm1, LPARAM parm2);
    afx_msg LRESULT OnHotKey(WPARAM wParam, LPARAM lParam);
    DECLARE_MESSAGE_MAP()
public:
    DECLARE_EVENTSINK_MAP()

public:
    // TODO: should be private
    static UINT WM_USER_RECORDINTERRUPTED;
    static UINT WM_USER_RECORDPAUSED;
    static UINT WM_USER_SAVECURSOR;
    static UINT WM_USER_GENERIC;
    static UINT WM_USER_RECORDSTART;

private:
    CFlashingWnd flashing_wnd_;
    CVideoWnd van_wnd_;
    CCamera camera_;
    CBasicMessageDlg *basic_msg_;
    double zoom_;
    CPoint zoomed_at_;
    DWORD zoom_when_;
    int zoom_direction_;
    bool show_message_;

    void DisplayRecordingStatistics(CDC &srcDC);
    void DisplayBackground(CDC &srcDC);
    void DisplayRecordingMsg(CDC &srcDC);
    bool SaveAppSettings();
    void SaveProducerCommand();

    bool captureScreenFrame(const CRect &rectView, bool bDisableRect = true);
    bool RecordVideo(CRect rectFrame, int fps, const char *szFileName);
    UINT RecordVideo();
    static UINT RecordThread(LPVOID pParam);
    bool RunViewer(const CString &strNewFile);
    bool RunProducer(const CString &strNewFile);
    void DisplayAutopanInfo(CRect rc);
    bool ConvertToMP4(const CString &sInputAVI, const CString &sOutputMP4, const CString &sOutBareName);
    // dialog controls
};

#ifndef _DEBUG // debug version in vscapView.cpp
inline CRecorderDoc *CRecorderView::GetDocument()
{
    return (CRecorderDoc *)m_pDocument;
}
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

// External Variables
extern HWND g_hWndGlobal;
extern bool g_bRecordState;
extern CRect g_rc;
extern CRect g_rcUse;
extern CRect g_rcClip;
extern CRect g_old_rcClip;
extern CRect g_rcOffset;
extern CPoint g_ptOrigin;

extern CString g_strCodec;

// extern LPWAVEFORMATEX pwfx;

// Video Compress Parameters
//extern void GetVideoCompressState(HIC hic, DWORD fccHandler);
extern void SetVideoCompressState(HIC hic, DWORD fccHandler);
// extern void AllocCompressFormat(DWORD& dwCbwFX);
