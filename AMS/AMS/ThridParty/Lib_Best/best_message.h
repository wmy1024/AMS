
#ifndef IBESTMESSAGE_H
#define IBESTMESSAGE_H
	#if (defined _WIN32)||(defined _WIN64)
		#if !defined( BEST_FUNCTION_CALL_MODE )
			#define BEST_FUNCTION_CALL_MODE		__stdcall
		#endif
		#else
			#define BEST_FUNCTION_CALL_MODE
		#endif
	#if (defined _WIN32)||(defined _WIN64)
		typedef char				int8;
		typedef short				int16;
		typedef int					int32;
		typedef __int64				int64;
		typedef unsigned char		uint8;
		typedef unsigned short		uint16;
		typedef unsigned int		uint32;
		typedef unsigned __int64	uint64;
	#else
		#include <sys/types.h>
//        #if defined(__linux__)
			#include <stdint.h>
//        #endif
		typedef int8_t				int8;
		typedef int16_t				int16;
		typedef int32_t				int32;
		typedef int64_t				int64;
		typedef uint8_t				uint8;
		typedef uint16_t			uint16;
		typedef uint32_t			uint32;
		typedef uint64_t			uint64;
	#endif

#define RPC_EHADLENGTH	40
#define MAX_BEST_BUFF_LEN 4194304 //��󳤶�Ϊ40M
#define GET_PRC_TOTAL_LENGTH(buff) (*((int32*)((char*)(buff) + 8)))

namespace best_protocol
{
	///Prev desc.
	class IBestBase;
	class IBestMessage;
	class IBestRPCHead;
	class IBestHeadMessage;
	class IBestDataMessage;
	class IBestGroup;
	class IBestRecord;
	class IBestField;

    ///�ֶ�ֵ����
	enum FIELD_VALUE_TYPE {
		VT_NONE     = 0,   ///< unkown type
		VT_INT8     = 1,   ///< 8bytes integer  
		VT_INT16    = 2,   ///< 16bytes integer  
		VT_INT32    = 3,   ///< 32bytes integer  
		VT_INT64    = 4,   ///< 64bytes integer  
		VT_STRING   = 5,   ///< string 
		VT_RAWDATA  = 6    ///< binary
	};

	///BEST��������
	enum BEST_OBJECT_TYPE {
		OBJ_NONE               = 0,  ///< unkown best object
		OBJ_BEST_FIELD         = 1,  ///< �ֶ�����
		OBJ_BEST_RECORD        = 2,  ///< ��¼����
		OBJ_BEST_GROUP         = 3,  ///< ���м�
		OBJ_BEST_MESSAGE       = 4,  ///< Best��Ϣ
		OBJ_BEST_RPC_HEAD      = 5,  ///< BestЭ��һ��RPC��Ϣ
		OBJ_BEST_HEAD_MESSAGE  = 6,  ///< BestЭ�����ͷ����Ϣ
		OBJ_BEST_DATA_MESSAGE  = 7   ///< BestЭ������������Ϣ 
	};

	///���ݰ�����
	enum PACKET_TYPE {
		PACKTTYPE_NONE         = 0,  ///< unkown packet type
		PACKTTYPE_REQUEST      = 1,  ///< ����
		PACKTTYPE_RESPONSE     = 2,  ///< Ӧ��
		PACKTTYPE_PUSH         = 3,   ///< ����
		PACKTTYPE_ROLLBACK     = 4,  ///�ع�����
		
	};

	enum PROTOCAL_TYPE 
	{
		BEST_PROTOCAL_NONE,
		BEST_MEASSAGE,
		BEST_RPC,
		BEST_HEAD_STAMP,
		BEST_DATA_RAW,
		BEST_DATA_JSON,
		BEST_DATA_XML
	};

	enum HEAD_MESSAGE_FIELD
	{
		HEAD_MSG_TYPE,
		HEAD_PACKTYPE,
		HEAD_HEADLENGTH,
		HEAD_CONTENTLENGTH,
		HEAD_CONTENENCODING,
		HEAD_SESSIONID,
		HEAD_BUSINESSID,
		HEAD_CATEGORYID,
		HEAD_MSGSEQNUM,
		HEAD_SENDIERD,
		HEAD_TARGETID,
		HEAD_SENDDINGTIME,
		HEAD_CHARSET,
		HEAD_BYTEORDER,
		HEAD_COMPRESSMETHOD,
		HEAD_ENCRYPTMETHOD,
		HEAD_CHECKSUM,
		HEAD_PRIORITY,
		HEAD_USRDATALENGTH,
		HEAD_USRDATA,
		HEAD_SYSTEM = 100
	};
	const uint8	RPC_HEAD_SUC = 0;
	const uint8 RPC_HEAD_FAIL = -1;
	const uint8 RPC_HEAD_TIME_OUT = -2;	// ��ʱ

	enum ERROR_NO
	{
		GW_ERROR_UNKNOW = 1,						// δ֪����
		GW_ERROR_NO_SESSION_ID,						// �Ự�Ų�����
		GW_ERROR_SESSION_INVALID,					// �Ự����Ч
		GW_ERROR_LOGIN_FAILED,						// ��½ʧ��
		GW_ERROR_NO_SUPPORT_FUNCTION_ID,			// ҵ���������ʹ���
		GW_ERROR_NEED_PERMISSION,					// Ȩ�޲���
		GW_ERROR_PARAM_ERROR,						// ��������
	};

	class BestIterator
	{
	public:
		///��ȡ��������һ���ڵ�
		virtual void BEST_FUNCTION_CALL_MODE First() = 0;
		///���ص�������һ�����
		virtual void BEST_FUNCTION_CALL_MODE Next() = 0;
		///�ж��Ƿ񻹴�����һ�����f
		virtual bool BEST_FUNCTION_CALL_MODE IsDone() = 0;
		//ɾ����������ǰ�ڵ�
		virtual bool BEST_FUNCTION_CALL_MODE Erase() = 0;

		virtual IBestBase* CurrentItem() const = 0;
	};
	
	/**
	 @class IBestBase
	 @describe Best�����ͳһ����
	*/
	class IBestBase
	{
	public:
		///�������ü�������������
		virtual IBestBase*  BEST_FUNCTION_CALL_MODE AddRef() = 0;

		///�������ü�������Ϊ0ʱ�ͷ�����
		virtual uint64  BEST_FUNCTION_CALL_MODE Release() = 0;

		///����BEST��������
		virtual BEST_OBJECT_TYPE  BEST_FUNCTION_CALL_MODE GetBestType() = 0;

		///������������
		virtual int32 BEST_FUNCTION_CALL_MODE SetOwner(IBestBase* best_base) = 0;

		///��ȡ��������
		virtual IBestBase* BEST_FUNCTION_CALL_MODE GetOwner() = 0;

		//��ȡ��ǰ�ֶε�Э��
		virtual const PROTOCAL_TYPE BEST_FUNCTION_CALL_MODE GetProtocal() = 0;
	};

	/**
	@class IBestSerializer
	@describe BEST���л�/�����л���
	*/
	class IBestSerializer
	{
	public:
		/**
		 @method SerializeXXX
		 @note   ���л���Ϣ,�ظ���,��¼,�ֶ�
		 @param 
		    len: [out] �������л���ĳ���
		 @return
		    �������л����buffer���䳤��Ϊ��������$len��ֵ��NULL��ʾ���л�ʧ��
			GetErrorNo()�ɷ��ش����,GetErrorString()���ش���ԭ��
		*/
		virtual const void*  BEST_FUNCTION_CALL_MODE SerializeMessage(int32& len, IBestMessage* message) = 0;
		virtual const void*  BEST_FUNCTION_CALL_MODE SerializeRpcMessage(int32& len, IBestRPCHead* bestRpchead) = 0;
		virtual const void*  BEST_FUNCTION_CALL_MODE SerializeHeadMessage(int32& len, IBestHeadMessage* headMessage) = 0;
		virtual const void*  BEST_FUNCTION_CALL_MODE SerializeDataHeadMessage(int32& len, IBestHeadMessage* head_message)=0;
		virtual const void*  BEST_FUNCTION_CALL_MODE SerializeDataMessage(int32& len, IBestDataMessage* headMessage) = 0;
		virtual const void*  BEST_FUNCTION_CALL_MODE SerializeGroup(int32& len,IBestGroup* bestGroup) = 0;
		virtual const void*  BEST_FUNCTION_CALL_MODE SerializeRecord(int32& len, IBestRecord* bestRecord) = 0;
		virtual const void*  BEST_FUNCTION_CALL_MODE SerializeField(int32& len, IBestField* bestField) = 0;
		//��ȡ��ǰ�ֶε�Э��
		virtual const PROTOCAL_TYPE BEST_FUNCTION_CALL_MODE GetProtocal() = 0;


		/**
		 @method DeserializeXXX
		 @note   �����л���Ϣ,�ظ���,��¼,�ֶ�
		 @param
		   ��һ������: ��buffer���ݷ����л���Ŀ�����
		   buffer: [IN] ����������
		   len: [IN] buffer�ĳ���
		@return
		   0:���л��ɹ�������ʧ�ܡ�
		   GetErrorNo()�ɷ��ش����,GetErrorString()���ش���ԭ��
		*/
		virtual int BEST_FUNCTION_CALL_MODE DeserializeMessage(IBestMessage* message, const void* buffer, const int32& len) = 0;
		virtual int BEST_FUNCTION_CALL_MODE DeserializeRpcMessage(IBestRPCHead* best_rpchead, const void* buffer, const int32& len) = 0;
		virtual int BEST_FUNCTION_CALL_MODE DeserializeHeadMessage(IBestHeadMessage* headMessage, const void* buffer, const int32& len) = 0;
		virtual int BEST_FUNCTION_CALL_MODE DeserializeDataHeadMessage(IBestHeadMessage* head_message, const void* buffer, const int32& len)=0;
		virtual int BEST_FUNCTION_CALL_MODE DeserializeDataMessage(IBestDataMessage* dataMessage, const void* buffer, const int32& len) = 0;
		virtual int BEST_FUNCTION_CALL_MODE DeserializeGroup(IBestGroup* group, const void* buffer, const int32& len)       = 0;
		virtual int BEST_FUNCTION_CALL_MODE DeserializeRecord(IBestRecord* record, const void* buffer, const int32& len)    = 0;
		virtual int BEST_FUNCTION_CALL_MODE DeserializeField(IBestField* field, const void* buffer, const int32& len)       = 0;

		///�������л�����ID
		virtual const char* BEST_FUNCTION_CALL_MODE GetProtocol() = 0;

		///��ȡ�����
		virtual int BEST_FUNCTION_CALL_MODE GetErrorNo() = 0;

		///��ȡ����ԭ��
		virtual const char* BEST_FUNCTION_CALL_MODE GetErrorString(int err) = 0;
	};

	/**
	@class IBestStream
	@describe BEST��
	*/
	class IBestStream
	{
	public:
		///���л�����
		virtual const void*  BEST_FUNCTION_CALL_MODE Serialize(int32* len) = 0;
		///�����л�
		virtual int32 BEST_FUNCTION_CALL_MODE Deserialize() = 0;//����Э������
		
		///������
		virtual int32	BEST_FUNCTION_CALL_MODE SetBuffer(const void* buffer, const int32& len) = 0;//����Э������
		///��ȡ��
		virtual void*  BEST_FUNCTION_CALL_MODE GetBuffer(int32* len) = 0;//��ȡЭ������
		///������״̬. 1:���� 0:������
		virtual int32  BEST_FUNCTION_CALL_MODE Status() = 0;
		///����/��ȡ���л���
		virtual int32   BEST_FUNCTION_CALL_MODE SetBestSerializer(IBestSerializer* serializer) = 0;

		virtual IBestSerializer* BEST_FUNCTION_CALL_MODE GetBestSerializer() = 0;
	};
	
	/**
	@class IBestField
	@describe BEST�ֶ�
	*/
	class IBestField :public IBestBase, public IBestStream
	{
	public:
		virtual BEST_OBJECT_TYPE  BEST_FUNCTION_CALL_MODE GetBestType() { return OBJ_BEST_FIELD; }
		/*******************��ȡ�����ö�Ӧ��Filedֵ*****************/
		virtual uint8	BEST_FUNCTION_CALL_MODE GetInt8() const = 0;
		virtual void BEST_FUNCTION_CALL_MODE SetInt8(uint8 val) = 0;
		virtual uint16	BEST_FUNCTION_CALL_MODE GetInt16() const = 0;
		virtual void BEST_FUNCTION_CALL_MODE SetInt16(uint16 val) = 0;
		virtual uint32	BEST_FUNCTION_CALL_MODE GetInt32() const = 0;
		virtual void BEST_FUNCTION_CALL_MODE SetInt32(uint32 val) = 0;
		virtual uint64	BEST_FUNCTION_CALL_MODE GetInt64() const = 0;
		virtual void BEST_FUNCTION_CALL_MODE SetInt64(uint64 val) = 0;
		virtual const char* BEST_FUNCTION_CALL_MODE GetString() const = 0;
		virtual void BEST_FUNCTION_CALL_MODE SetString(const char* val) = 0;
		//virtual const void* BEST_FUNCTION_CALL_MODE GetRawData(int* data_len ) const = 0;
		virtual int32 BEST_FUNCTION_CALL_MODE GetRawDataLen() const  = 0;
		virtual void* BEST_FUNCTION_CALL_MODE GetRawData(int* data_len) = 0;
		virtual void BEST_FUNCTION_CALL_MODE SetRawData(const void* raw_data, int data_len) = 0;
		///��ȡ�ֶε���������
		virtual FIELD_VALUE_TYPE BEST_FUNCTION_CALL_MODE GetValueType() = 0;
		///����һ�������Ƶ�����
		virtual int32 BEST_FUNCTION_CALL_MODE CopyFrom(const IBestField *other) = 0;
		///��������
		virtual IBestField* BEST_FUNCTION_CALL_MODE Clone() = 0;
		///��ȡ�ֶζ�Ӧ��tag
		virtual uint32 BEST_FUNCTION_CALL_MODE GetTag() = 0;
	};

	/**
	 @class IBestRecord
	 @describe BEST��¼
	*/
	class IBestRecord : public IBestBase, public IBestStream
	{
	public:
		virtual BEST_OBJECT_TYPE  BEST_FUNCTION_CALL_MODE GetBestType() { return OBJ_BEST_RECORD; }
		///��ȡ$tag���ֶ�,NULL��ʾ������
		virtual IBestField*  BEST_FUNCTION_CALL_MODE GetField(const int32& tag) = 0;

		///����$tag���ֶ�
		virtual void BEST_FUNCTION_CALL_MODE SetField(const int32& tag, IBestField* field) = 0;

		///�ж�$tag���ֶ��Ƿ����
		virtual bool BEST_FUNCTION_CALL_MODE IsExistField(const int32& tag) = 0;
		
		///����һ�������Ƶ�����
		virtual int32 BEST_FUNCTION_CALL_MODE CopyFrom(const IBestRecord *other) = 0;

		///��������
		virtual IBestRecord* BEST_FUNCTION_CALL_MODE Clone() = 0;

		///��ȡ�ֶε�����
		virtual BestIterator* BEST_FUNCTION_CALL_MODE GetIterator() = 0;

	};

	/**
	 @class IBestGroup
	 @describe BEST�ظ���
	*/
	class  IBestGroup : public IBestBase, public IBestStream
	{		
	public:
		virtual BEST_OBJECT_TYPE  BEST_FUNCTION_CALL_MODE GetBestType() { return OBJ_BEST_GROUP; }
		///����һ����¼,�������Ӻ�ļ�¼����
		virtual IBestRecord * BEST_FUNCTION_CALL_MODE AddRecord() = 0;
		///����һ���Ѵ��ڵļ�¼
		virtual int BEST_FUNCTION_CALL_MODE AddRecord(IBestRecord * bestRecord) = 0;
		///��ȡ��¼������
		virtual BestIterator* BEST_FUNCTION_CALL_MODE GetIterator() = 0;
		///����һ�������Ƶ�����
		virtual int32 BEST_FUNCTION_CALL_MODE CopyFrom(const IBestGroup* other) = 0;
		///��������
		virtual IBestGroup* BEST_FUNCTION_CALL_MODE Clone() const = 0;
	};

	/**
	@class IBestDataMessage
	@describe BEST������Ϣ
	*/
	class IBestDataMessage : public IBestBase, public IBestStream
	{
	public:
		virtual BEST_OBJECT_TYPE  BEST_FUNCTION_CALL_MODE GetBestType() { return OBJ_BEST_DATA_MESSAGE; }
		///����һ�������Ƶ�����
		virtual int32 BEST_FUNCTION_CALL_MODE CopyFrom(const IBestDataMessage *other) = 0;
		///��������
		virtual IBestDataMessage* BEST_FUNCTION_CALL_MODE Clone() = 0;

		virtual void BEST_FUNCTION_CALL_MODE SetGroup(const int32& flag, IBestGroup* group) = 0;

		virtual IBestGroup* BEST_FUNCTION_CALL_MODE GetGroup(const int32& flag) = 0;

		virtual bool BEST_FUNCTION_CALL_MODE IsExitGroup(const int32& flag) = 0; 

		///��ȡ$tag���ֶ�,NULL��ʾ������
		virtual IBestField*  BEST_FUNCTION_CALL_MODE GetField(const int32& tag) = 0;

		///����$tag���ֶ�
		virtual void BEST_FUNCTION_CALL_MODE SetField(const int32& tag, IBestField* field) = 0;

		///�ж�$tag���ֶ��Ƿ����
		virtual bool BEST_FUNCTION_CALL_MODE IsExistField(const int32& tag) = 0;

		///��ȡ�ֶε�����
		virtual BestIterator* BEST_FUNCTION_CALL_MODE GetIterator() = 0;

		virtual int32	BEST_FUNCTION_CALL_MODE SetHeadBuffer(const void* buffer, const int32& len) = 0;
		///��ȡͷ����
		virtual void*  BEST_FUNCTION_CALL_MODE GetHeadBuffer(int32* len) = 0;
		///���л�ͷ������
		virtual const void*  BEST_FUNCTION_CALL_MODE SerializeHead(int32* len) = 0;
		///�����л�ͷ��
		virtual int32 BEST_FUNCTION_CALL_MODE DeserializeHead() = 0;
		///��ȡͷ��
		virtual IBestHeadMessage* BEST_FUNCTION_CALL_MODE GetDataHeadMessage() = 0;
		
	};

	/**
	@class IBestHeadMessage
	@describe BESTͷ����Ϣ
	*/
	class IBestHeadMessage : public IBestBase, public IBestStream
	{
	public:
		virtual BEST_OBJECT_TYPE  BEST_FUNCTION_CALL_MODE GetBestType() { return OBJ_BEST_HEAD_MESSAGE; }

		///��ȡͷ������,0��ʾ��ǰ�޷���ȡͷ������
		virtual int32 BEST_FUNCTION_CALL_MODE GetHeadLength() = 0;

		///��ȡ���ݳ���,0��ʾ��ǰ�޷���ȡ���ݳ���
		virtual int32 BEST_FUNCTION_CALL_MODE GetDataLength() = 0;

		/******************************************�������ݲ�******************************************/
		///�������ݲ���Ϣ
		virtual int32 BEST_FUNCTION_CALL_MODE SetDataMessage(IBestDataMessage* dataMsg) = 0;
		///��ȡ���ݲ���Ϣ
		virtual IBestDataMessage* BEST_FUNCTION_CALL_MODE GetDataMessage() = 0;
		///����һ����Ϣ���Ƶ�����
		virtual int32 BEST_FUNCTION_CALL_MODE CopyFrom(const IBestHeadMessage* other) = 0;
		///��������
		virtual IBestHeadMessage* BEST_FUNCTION_CALL_MODE Clone() = 0;
		/**********************************��ȡ������*************************/
		///��ȡ$tag���ֶ�,NULL��ʾ������
		virtual IBestField*  BEST_FUNCTION_CALL_MODE GetField(const int32& tag) = 0;

		///����$tag���ֶ�
		virtual void BEST_FUNCTION_CALL_MODE SetField(const int32& tag, IBestField* field) = 0;

		///�ж�$tag���ֶ��Ƿ����
		virtual bool BEST_FUNCTION_CALL_MODE IsExistField(const int32& tag) = 0;

		///��ȡ�ֶε�����
		virtual BestIterator* BEST_FUNCTION_CALL_MODE GetIterator() = 0;

	};

	/**
	@class IBestRPCHead
	@describe BESTRPCͷ��
	*/
	class IBestRPCHead :public IBestBase, public IBestStream
	{
	public:
		virtual BEST_OBJECT_TYPE  BEST_FUNCTION_CALL_MODE GetBestType() { return OBJ_BEST_RPC_HEAD; }
		/*****************************bestheadЭ��̶�ͷ������*******************************/
		///��ȡЭ���ʶ��
		virtual int32 BEST_FUNCTION_CALL_MODE GetBestProtTag() = 0;
		///��ȡЭ���ʶ��
		virtual void  BEST_FUNCTION_CALL_MODE SetBestProtTag(const int32& protTag) = 0;
		///��ȡЭ��汾
		virtual int32 BEST_FUNCTION_CALL_MODE GetBestProtVersion() = 0;
		///����Э��汾
		virtual void  BEST_FUNCTION_CALL_MODE SetBestProtVersion(const int32& protVersion) = 0;
		///��ȡЭ���ܳ���
		virtual uint32 BEST_FUNCTION_CALL_MODE GetTotalLenght() = 0;
		///��ȡ״̬��
		virtual uint8  BEST_FUNCTION_CALL_MODE GetStatus() = 0;
		///����״̬��
		virtual void BEST_FUNCTION_CALL_MODE SetStatus(const uint8& status) = 0;
		//��ȡ������
		virtual PACKET_TYPE BEST_FUNCTION_CALL_MODE GetPackType() = 0;
		//���ð�����
		virtual void BEST_FUNCTION_CALL_MODE SetPackType(const PACKET_TYPE& packType) = 0;
		///��ȡ�Ӱ����� 
		virtual uint8 BEST_FUNCTION_CALL_MODE GetSubHeadNum() = 0;
		///��ȡ���к�
		virtual uint64 BEST_FUNCTION_CALL_MODE GetSeqNum() = 0;
		///�������к�
		virtual void  BEST_FUNCTION_CALL_MODE SetSeqNum(const uint64& seqNum) = 0;
		///��ȡ�Ự��
		virtual uint64 BEST_FUNCTION_CALL_MODE GetSessionNum() = 0;
		///���ûỰ��
		virtual void  BEST_FUNCTION_CALL_MODE SetSessionNum(const uint64& sessionNum) = 0;
		///��ȡ���ܺ�
		virtual uint32 BEST_FUNCTION_CALL_MODE GetFuncNo() = 0;
		///���ù��ܺ�
		virtual void  BEST_FUNCTION_CALL_MODE SetFuncNo(const uint32& funcNo) = 0;
		///��ȡУ��λ
		virtual uint32 BEST_FUNCTION_CALL_MODE GetCRCCheck() = 0;
		///����У��λ
		virtual void  BEST_FUNCTION_CALL_MODE SetCRCCheck(const uint32& crc) = 0;

		///����һ�������Ƶ�����
		virtual int32 BEST_FUNCTION_CALL_MODE CopyFrom(const IBestRPCHead *other) = 0;
		///��������
		virtual IBestRPCHead* BEST_FUNCTION_CALL_MODE Clone() = 0;
	};

	/**
	@class IBestMessge
	@describe BEST��Ϣͷ��
	*/
	class IBestMessge : public IBestBase, public IBestStream
	{
	public:
		virtual BEST_OBJECT_TYPE  BEST_FUNCTION_CALL_MODE GetBestType() { return OBJ_BEST_MESSAGE; }
		///��ȡRPCͷ
		virtual IBestRPCHead* GetRpcHead() = 0;
		///����RPCͷ
		virtual int32 SetRpcHead(IBestRPCHead* rpc_head) = 0;
		/*****************************����HeadЭ���*******************************/
		///���ͷ��Ϣ
		virtual int32  BEST_FUNCTION_CALL_MODE AddHeadMessage(IBestHeadMessage* headMessage) = 0;
		virtual IBestHeadMessage*  BEST_FUNCTION_CALL_MODE AddHeadMessage() = 0;
		///����һ����Ϣ���Ƶ�����
		virtual int32 BEST_FUNCTION_CALL_MODE CopyFrom(const IBestMessge *bestMessage) = 0;	
		///��������
		virtual IBestMessge* BEST_FUNCTION_CALL_MODE Clone() = 0;
		
		///��ȡ�ֶε�����
		virtual BestIterator* BEST_FUNCTION_CALL_MODE GetIterator() = 0;

		///�ͷ���Ϣ���л��ͷ����ﻯbuffer�ֶ�
		virtual int32 ReleaseBuffer(bool isReleaseData = false) = 0;


	};

	/**
	 @class IBestMessgeFactory
	 @describe BEST��Ϣ����
	*/
	class IBestMessgeFactory
	{
	public:
		///����BestMessage��Ϣ������Э��������л���
		virtual IBestMessge* BEST_FUNCTION_CALL_MODE CreateBestMessage(PROTOCAL_TYPE protocal = BEST_MEASSAGE) = 0;
		///����BestRPCͷ����Ϣ
		virtual IBestRPCHead* BEST_FUNCTION_CALL_MODE CreateRpcHead(PROTOCAL_TYPE protocal = BEST_RPC) = 0;
		///����Bestͷ����Ϣ
		virtual IBestHeadMessage* BEST_FUNCTION_CALL_MODE CreateHeadMessage(PROTOCAL_TYPE protocal = BEST_HEAD_STAMP) = 0;
		///����BestMessage��Ϣ������Э��������л���
		virtual IBestDataMessage* BEST_FUNCTION_CALL_MODE CreateDataMessage(PROTOCAL_TYPE protocal = BEST_DATA_RAW) = 0;
		///����BestGroup��Ϣ������Э��������л���
		virtual IBestGroup* BEST_FUNCTION_CALL_MODE CreateBestGroup(PROTOCAL_TYPE protocal = BEST_PROTOCAL_NONE) = 0;
		///����Best��¼��Ϣ������Э��������л���
		virtual IBestRecord* BEST_FUNCTION_CALL_MODE CreateBestRecord(PROTOCAL_TYPE protocal = BEST_PROTOCAL_NONE) = 0;
		///����Best�ֶΣ�����Э��������л���
		virtual IBestField* BEST_FUNCTION_CALL_MODE CreateBestField(PROTOCAL_TYPE protocal = BEST_HEAD_STAMP) = 0;
		///����Э�鷵�����л���
		virtual IBestSerializer* BEST_FUNCTION_CALL_MODE GetSerializer(PROTOCAL_TYPE protocal = BEST_HEAD_STAMP) = 0;
	};


};

	#ifdef __cplusplus
	extern "C" {
	#endif
		best_protocol::IBestMessgeFactory * BEST_FUNCTION_CALL_MODE CreateBestMessgeFactrotyInstance();
		int32  BEST_FUNCTION_CALL_MODE InitBestMessge();
	#ifdef __cplusplus
	};
	#endif

#endif
