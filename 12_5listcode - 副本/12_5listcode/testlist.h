//����  �����ȹ���Ϣ�� ��ЧԪ�ظ��������������
//��̬˳���
#define N 100
typedef int SLDDataType;
struct seqList1
{
	SLDDataType _data[N];
	int _size;
};

typedef struct seqList
{
	SLDDataType* _data;
	int _size;
	int _capacity;
}seqList;

void initseqList(seqList *);
//��������ɾ���
//β�壺��˳�������һ����Ч����ĩβ�����µ�����
void seqListCheckCapacity(seqList* sl);//�������
void seqListpushBack(seqList* sl,SLDDataType val);
void seqListpopBack(seqList* sl);
void seqLstPrint(seqList* sl);
SLDDataType seqListAt(seqList* sl, int pos);
int seqListEmpty(seqList* sl);
int seqListSize(seqList* sl);
void seqListPushFront(seqList* sl, SLDDataType val);//ͷ��
void seqListPopFront(seqList* sl, SLDDataType val);//ͷɾ
void seqListPopFront(seqList* sl, SLDDataType val);//ͷɾ
void seqListInsert(seqList* sl, int pos, SLDDataType val);//����λ�ò�������
void seqListFind(seqList* sl, SLDDataType val);//����ĳһԪ��
void seqListDestroy(seqList* sl);//����



