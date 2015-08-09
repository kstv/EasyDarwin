/*
	Copyright (c) 2013-2015 EasyDarwin.ORG.  All rights reserved.
	Github: https://github.com/EasyDarwin
	WEChat: EasyDarwin
	Website: http://www.easydarwin.org
*/
/*
    File:       EasyHLSSession.h
    Contains:   HLS
*/
#include "QTSS.h"
#include "OSRef.h"
#include "StrPtrLen.h"
#include "ResizeableStringFormatter.h"
#include "MyAssert.h"
#include "QTSServerInterface.h"

#include "ReflectorStream.h"
#include "SourceInfo.h"
#include "OSArrayObjectDeleter.h"
#include "EasyNVSourceAPI.h"
#include "EasyHLSAPI.h"

#ifndef __EASY_HLS_SESSION__
#define __EASY_HLS_SESSION__

class EasyHLSSession
{
    public:
        EasyHLSSession(StrPtrLen* inSourceID);
        virtual ~EasyHLSSession();
        
        //����ģ������
        static void Initialize(QTSS_ModulePrefsObject inPrefs);

        // ACCESSORS
        
        OSRef*          GetRef()            { return &fRef; }
        OSQueueElem*    GetQueueElem()      { return &fQueueElem; }
	
        StrPtrLen*      GetSessionID()     { return &fHLSSessionID; }
		QTSS_Error		ProcessData(int _chid, int mediatype, char *pbuf, NVS_FRAME_INFO *frameinfo);
		QTSS_Error		HLSSessionStart(char* rtspUrl);
		QTSS_Error		HLSSessionRelease();
   
    private:

        //HLSSession�б���EasyHLSModule��sHLSSessionMapά��  
        OSRef       fRef;
        StrPtrLen   fHLSSessionID;

        OSQueueElem fQueueElem; 

		//NVS Handle
		Easy_NVS_Handle	fNVSHandle;
		//HLS Handle
		Easy_HLS_Handle fHLSHandle;
		
		//TS timestamp ms���Զ���ʱ���
		int tsTimeStampMSsec;


		//����Raw���ݱ���
		FILE* fTest;

		static UInt32	sM3U8Version;
		static Bool16	sAllowCache;
		static UInt32	sTargetDuration;
		static UInt32	sPlaylistCapacity;
		static char*	sHTTPRootDir;
};

#endif
