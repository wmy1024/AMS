
#ifndef DEFAULT_BEST_MESSAGE_H
#define DEFAULT_BEST_MESSAGE_H
#include "default_bestIteror.h"
#include"best_message.h"
#include <list>
#include "atomic_count.h"
#include "default_message_pool.h"
using namespace best_protocol;
class DefaultBestMessge :public IBestMessge
{
	//friend class DefaultBestSerializer;
private:
	atomic_count m_ref;
	
public:
	DefaultBestMessge(){
		m_best_buffer = NULL;
		m_status = 0;
		m_rpc_head = NULL;
		m_protocol_type = BEST_MEASSAGE;
		m_best_iterator.Initail(&m_list_head_message);
	}
	virtual ~DefaultBestMessge(){};
	///��ȡRPCͷ
	virtual IBestRPCHead* GetRpcHead();
	///����RPCͷ
	virtual int32 SetRpcHead(IBestRPCHead* rpc_head);
	/*****************************����HeadЭ���*******************************/
	///���ͷ��Ϣ
	virtual int32  BEST_FUNCTION_CALL_MODE AddHeadMessage(IBestHeadMessage* head_message);
	virtual IBestHeadMessage*  BEST_FUNCTION_CALL_MODE AddHeadMessage();

	///��ȡ�ֶε�����
	virtual BestIterator* BEST_FUNCTION_CALL_MODE GetIterator();
	///����һ����Ϣ���Ƶ�����
	virtual int32 BEST_FUNCTION_CALL_MODE CopyFrom(const IBestMessge *best_message);
	///��������
	virtual IBestMessge* BEST_FUNCTION_CALL_MODE Clone();

	//��ȡ��ǰ�ֶε�Э��
	virtual const PROTOCAL_TYPE BEST_FUNCTION_CALL_MODE GetProtocal();
	//����Э��
	virtual int32 BEST_FUNCTION_CALL_MODE SetProtocal(PROTOCAL_TYPE protpcal);

public:
	/************************IBestBase�ӿ�*************************/
	///�������ü�������������
	virtual IBestBase*  BEST_FUNCTION_CALL_MODE AddRef();
	uint64 BEST_FUNCTION_CALL_MODE Release();

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
	virtual int32  BEST_FUNCTION_CALL_MODE Status(){ return m_status; }
	///�������л���
	virtual int32   BEST_FUNCTION_CALL_MODE SetBestSerializer(IBestSerializer* serializer){ return 0; }
	///��ȡ���л���
	virtual IBestSerializer* BEST_FUNCTION_CALL_MODE GetBestSerializer(){ return 0; }
	///�ͷŶ����ڴ�
	virtual int32 ReleaseBuffer(bool isReleaseData = false);
private:
	IBestRPCHead* m_rpc_head;
	BestBuffer* m_best_buffer;
	PROTOCAL_TYPE m_protocol_type;
	std::list<IBestBase*> m_list_head_message;
	DefaultBestListIterator m_best_iterator;
	int32 m_status;
};

#endif