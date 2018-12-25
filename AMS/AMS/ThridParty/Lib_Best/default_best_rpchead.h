#ifndef DEFAULT_BEST_RPCHEAD_H
#define DEFAULT_BEST_RPCHEAD_H
#include"best_message.h"
#include <list>
#include "atomic_count.h"
#include "default_serializer.h"
#include <string.h>
#define PROT_TAG 1414743362
#define PROT_VERSION 925
#pragma pack(1)
typedef struct BestRpcStruct_t
{
	BestRpcStruct_t()
	{
		memset(this, 0, sizeof(BestRpcStruct_t));
		prot_tag = PROT_TAG;
		prot_version = PROT_VERSION;
	}
	int32 prot_tag;///Э���ʶ��
	int32 prot_version;///Э��汾��
	uint32 total_lenght;///Э���ܳ���
	uint8 status_code;///״̬��
	uint8 type;///������
	uint8 subnum;///�Ӱ���
	uint8 reserve;///����λ
	uint64 seq_num;///���
	uint64 session_num;///�Ự��
	uint32 fun_no;//���ܺ�
	uint32 crc_reserver;///crc����λ
}BestRpcStruct;

#pragma pack()
class DefaultBestRPCHead :public IBestRPCHead
{
private:
	atomic_count m_ref;
	PROTOCAL_TYPE m_protocol_type;
	int32 status;
public:
	DefaultBestRPCHead()
	{
		status = 0;
	}
	virtual ~DefaultBestRPCHead(){}
	BestRpcStruct m_best_rpc_struct;
	///��ȡЭ���ʶ��
	virtual int32 BEST_FUNCTION_CALL_MODE GetBestProtTag();
	///��ȡЭ���ʶ��
	virtual void  BEST_FUNCTION_CALL_MODE SetBestProtTag(const int32& prot_tag);
	///��ȡЭ��汾
	virtual int32 BEST_FUNCTION_CALL_MODE GetBestProtVersion();
	///����Э��汾
	virtual void  BEST_FUNCTION_CALL_MODE SetBestProtVersion(const int32& prot_version);
	///��ȡЭ���ܳ���
	virtual uint32 BEST_FUNCTION_CALL_MODE GetTotalLenght();

	virtual void BEST_FUNCTION_CALL_MODE SetTotalLenght(int32 len);
	///��ȡ״̬��
	virtual uint8  BEST_FUNCTION_CALL_MODE GetStatus();
	///����״̬��
	virtual void BEST_FUNCTION_CALL_MODE SetStatus(const uint8& status);
	//��ȡ������
	virtual PACKET_TYPE BEST_FUNCTION_CALL_MODE GetPackType();
	//���ð�����
	virtual void BEST_FUNCTION_CALL_MODE SetPackType(const PACKET_TYPE& pack_type);
	///��ȡ�Ӱ����� 
	virtual uint8 BEST_FUNCTION_CALL_MODE GetSubHeadNum();
	///�����Ӱ��� 
	virtual void BEST_FUNCTION_CALL_MODE SetSubHeadNum(uint8 sub_num);
	///��ȡ���к�
	virtual uint64 BEST_FUNCTION_CALL_MODE GetSeqNum();
	///�������к�
	virtual void  BEST_FUNCTION_CALL_MODE SetSeqNum(const uint64& seq_num);
	///��ȡ�Ự
	virtual uint64 BEST_FUNCTION_CALL_MODE GetSessionNum();
	///���ûỰ
	virtual void  BEST_FUNCTION_CALL_MODE SetSessionNum(const uint64& session_num);
	///��ȡ���ܺ�
	virtual uint32 BEST_FUNCTION_CALL_MODE GetFuncNo();
	///���ù��ܺ�
	virtual void  BEST_FUNCTION_CALL_MODE SetFuncNo(const uint32& fuc_no);
	///��ȡУ��λ
	virtual uint32 BEST_FUNCTION_CALL_MODE GetCRCCheck();
	///����У��λ
	virtual void  BEST_FUNCTION_CALL_MODE SetCRCCheck(const uint32& crc);
	//��ȡ��ǰ�ֶε�Э��
	virtual const PROTOCAL_TYPE BEST_FUNCTION_CALL_MODE GetProtocal();
	//����Э������
	virtual int32 BEST_FUNCTION_CALL_MODE SetProtocal(PROTOCAL_TYPE protpcal);
public:
	/************************IBestBase�ӿ�*************************/
	///�������ü�������������
	virtual IBestBase*  BEST_FUNCTION_CALL_MODE AddRef();

	///�������ü�������Ϊ0ʱ�ͷ�����
	virtual uint64  BEST_FUNCTION_CALL_MODE Release();

	///����BEST��������
	virtual BEST_OBJECT_TYPE  BEST_FUNCTION_CALL_MODE GetBestType(){ return OBJ_NONE; }

	///������������
	virtual int32 BEST_FUNCTION_CALL_MODE SetOwner(IBestBase* best_base){ return 0; }

	///��ȡ��������
	virtual IBestBase* BEST_FUNCTION_CALL_MODE GetOwner(){ return 0; }

	/****************************IBestStream�ӿ�******************************/
	///���л�����
	virtual const void*  BEST_FUNCTION_CALL_MODE Serialize(int32* len);
	///�����л�
	virtual int32 BEST_FUNCTION_CALL_MODE Deserialize();

	///������
	virtual int32	BEST_FUNCTION_CALL_MODE SetBuffer(const void* buffer, const int32& len);
	///��ȡ��
	virtual void*  BEST_FUNCTION_CALL_MODE GetBuffer(int32* len);
	///������״̬. 1:���� 0:������
	virtual int32  BEST_FUNCTION_CALL_MODE Status(){ return status; }
	///�������л���
	virtual int32   BEST_FUNCTION_CALL_MODE SetBestSerializer(IBestSerializer* serializer){ return 0; }
	///��ȡ���л���
	virtual IBestSerializer* BEST_FUNCTION_CALL_MODE GetBestSerializer(){ return 0; }
	///����һ�������Ƶ�����
	virtual int32 BEST_FUNCTION_CALL_MODE CopyFrom(const IBestRPCHead *other);
	///��������
	virtual DefaultBestRPCHead* BEST_FUNCTION_CALL_MODE Clone();
private:
	void Reset();

};
#endif