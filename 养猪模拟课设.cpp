#include<iostream>//ofstreamͷ�ļ� 
#include <fstream>
#include<cstdlib>//rand������ͷ�ļ� 
#include<cmath>//pow������ͷ�ļ� 
using namespace std;
struct Pig_node {
	int sty_number;
	int pig_type;
	double pig_weight;
	int pig_time;
	Pig_node* next;
};
//�����������������ʼ�����������Ϣ
double getRandData(int min, int max) {
	double m1 = (double)(rand() % 101) / 101;                  // ���� 0��1֮������С��,�õ���ֵ�����Ϊ(0,1)
	min++;                                                     //�� �����Ϊ(min+1,max),
	double m2 = (double)((rand() % (max - min + 1)) + min);    //���� min+1,max ֮�������������õ���ֵ��Ϊ[min+1,max]
	m2 = m2 - 1;
	double dSrc = m1 + m2;
	int iBit = 1;
	double retVal = 0.0;
	int  intTmp = 0;
	intTmp = (int)((dSrc + 0.5 / pow(10.0, iBit)) * pow(10.0, iBit));
	retVal = (double)intTmp / pow(10.0, iBit);
	return retVal;
}
//���������������ʼ���������ʱ��
int Time(int high, int low) {
	return rand() % (high - low + 1) + low;
}
//ˢ�����������Ϣ����
double Addweight(double weight) {
	switch (rand() % 13) {
		case(1):
			return weight + 0.1;
			break;
		case(2):
			return weight + 0.2;
			break;
		case(3):
			return weight + 0.3;
			break;
		case(4):
			return weight + 0.4;
			break;
		case(5):
			return weight + 0.5;
			break;
		case(6):
			return weight + 0.6;
			break;
		case(7):
			return weight + 0.7;
			break;
		case(8):
			return weight + 0.8;
			break;
		case(9):
			return weight + 0.9;
			break;
		case(10):
			return weight + 1.0;
			break;
		case(11):
			return weight + 1.1;
			break;
		case(12):
			return weight + 1.2;
			break;
	}
}
//����������Ϣ�����ļ�fileOutputsave.txt��
void Save(Pig_node* head) {
	ofstream fileOutputsave;
	ofstream fileOutputsavedata;
	fileOutputsave.open("fileOutputsave.txt", ios::out);
	fileOutputsavedata.open("fileOutputsavedata.txt", ios::out);
	fileOutputsave << "*****��ʾ��Ȧ����ϸ��Ϣ*****" << endl;
	Pig_node* p3 = head;
	while (p3 != NULL) {
		if (p3->pig_time == 0)
			p3 = p3->next;
		else {
			fileOutputsave << "������ࣺ";
			switch (p3->pig_type) {
				case(1): {
						fileOutputsave << "  ����  ";
						fileOutputsavedata << 1 << endl;
						break;
					}
				case(2): {
						fileOutputsave << " С���� ";
						fileOutputsavedata << 2 << endl;
						break;
					}
				case(3): {
						fileOutputsave << "�󻨰���";
						fileOutputsavedata << 3 << endl;
						break;
					}
			}
			fileOutputsave << "     " << "���������" << p3->pig_weight << "     " << "�������ʱ�䣺" << p3->pig_time << "     " << "��Ȧ��ţ�" << p3->sty_number << endl;
			fileOutputsavedata << p3->pig_weight << endl << p3->pig_time << endl << p3->sty_number << endl;
			p3 = p3->next;
		}
	}
}
//��������ˢ����������Ϣ
void Loop1(Pig_node* head) {
	Pig_node* p4 = head;
	Pig_node* p3 = head;
	while (p4 != NULL) {
		if(p4->pig_time==0)
			p4 = p4->next;
		else	{
			p4->pig_weight = Addweight(p4->pig_weight);
			p4->pig_time++;
			p4 = p4->next;
		}
	}
	Save(p3);
}
//��������Ϣ
void Cout(Pig_node* head) {
	cout << "*****��ʾ��Ȧ����ϸ��Ϣ*****" << endl;
	Pig_node* p4 = head;
	while (p4 != NULL) {
		if(p4->pig_time==0)
			p4 = p4->next;
		else {
			cout << "������ࣺ";
			switch (p4->pig_type) {
				case(1): {
						cout << "  ����  ";
						break;
					}
				case(2): {
						cout << " С���� ";
						break;
					}
				case(3): {
						cout << "�󻨰���";
						break;
					}
			}
			cout << '\t' << "���������" << p4->pig_weight << '\t' << "�������ʱ�䣺" << p4->pig_time << '\t' << "��Ȧ��ţ�" << p4->sty_number << endl;
			p4=p4->next;
		}

	}
	cout << "#####��Ҫ������ѯ��ǰ��Ȧ��Ϣ������1����Ҫ�˳���ǰ��ѯҳ�������������1����#####" << endl;
	int temp1;
	cin >> temp1;
	if (temp1 == 1) {
		Pig_node* p3 = head;
		Pig_node* p5 = head;
		Loop1(p3);
		Cout(p5);
	} else {
		cout << "###############��ѯ��ǰĳһ��Ȧ���������������������1###############" << endl;
		cout << "###############��ѯ��ǰĳһ��Ȧĳͷ���״̬��Ϣ������2###############" << endl;
		cout << "#####ͳ�Ƶ�ǰ��ÿ��Ʒ��������������ء�����ʱ��ֲ����������3#####" << endl;
		cout << "###########��ѯ��5��������ۼ�¼�����̶��Ĺ����¼������4############" << endl;
		cout << "##########################��ѯ��ǰ��Ȧ������5#########################" << endl;
		cout << "############################�˳�������0##############################" << endl;
	}
	Pig_node* p6 = head;
	Save(p6);
}
//��ʾ��ǰĳһ��Ȧ�����������������Ϣ
void f1(Pig_node* head) {
	int query_sty_number;
	int black_count(0), small_count(0), big_count(0), total_count(0);
	cout << "*****��ʾ��ǰĳһ��Ȧ�����������������Ϣ*****" << endl;
	cout << "*****������Ҫ��ѯ����Ȧ���*****" << endl;
	cin >> query_sty_number;
	Pig_node* p4 = head;
	while (p4 != NULL) {
		if(p4->pig_time==0)
			p4=p4->next;
		else {
			if (p4->sty_number == query_sty_number) {
				if (p4->pig_type == 1)
					black_count++;
				if (p4->pig_type == 2)
					small_count++;
				if (p4->pig_type == 3)
					big_count++;
			}
			p4 = p4->next;
		}
	}
	total_count=black_count+small_count+big_count;
	cout << "��Ȧ���Ϊ" << query_sty_number << "�����������Ϊ��" << total_count << '\t' << "��������Ϊ��" << black_count << '\t' << "С��������Ϊ��" << small_count << '\t' << "�󻨰���������" << big_count << endl;
	cout << "#####���������ѯĳһ��Ȧ�����������������Ϣ��������1�˳���ǰ��ѯҳ�������������1����#####" << endl;
	int temp1;
	cin >> temp1;
	if (temp1 == 1) {
		Pig_node* p3 = head;
		Pig_node* p5 = head;
		Loop1(p3);
		f1(p5);
	} else {
		cout << "###############��ѯ��ǰĳһ��Ȧ���������������������1###############" << endl;
		cout << "###############��ѯ��ǰĳһ��Ȧĳͷ���״̬��Ϣ������2###############" << endl;
		cout << "#####ͳ�Ƶ�ǰ��ÿ��Ʒ��������������ء�����ʱ��ֲ����������3#####" << endl;
		cout << "###########��ѯ��5��������ۼ�¼�����̶��Ĺ����¼������4############" << endl;
		cout << "##########################��ѯ��ǰ��Ȧ������5########################" << endl;
		cout << "############################�˳�������0##############################" << endl;
	}
	Pig_node* p6 = head;
	Save(p6);
}
//��ʾ��ǰĳһ��Ȧĳͷ���״̬��Ϣ
void f2(Pig_node* head) {
	int query_sty_number;
	cout << "*****��ʾ��ǰĳһ��Ȧĳͷ���״̬��Ϣ*****" << endl;
	cout << "*****������Ҫ��ѯ����Ȧ���*****" << endl;
	cin >> query_sty_number;
	cout << "��Ȧ���Ϊ" << query_sty_number << "����Ȧ�������Ϣ���£�" << endl;
	Pig_node* p4 = head;
	while (p4 != NULL) {
		if(p4->pig_time==0)
			p4=p4->next;
		else {
			if (p4->sty_number == query_sty_number) {
				cout << "������ࣺ";
				switch (p4->pig_type) {
					case(1): {
							cout << "  ����  ";
							break;
						}
					case(2): {
							cout << " С���� ";
							break;
						}
					case(3): {
							cout << "�󻨰���";
							break;
						}
				}
				cout << '\t' << "���������" << p4->pig_weight << '\t' << "�������ʱ�䣺" << p4->pig_time << endl;
			}
			p4 = p4->next;
		}
	}
	cout << "#####���������ѯ��Ȧĳͷ���״̬��Ϣ������1���˳���ǰ��ѯҳ�������������1����#####" << endl;
	int temp1;
	cin >> temp1;
	if (temp1 == 1) {
		Pig_node* p3 = head;
		Pig_node* p5 = head;
		Loop1(p3);
		f2(p5);
	} else {
		cout << "###############��ѯ��ǰĳһ��Ȧ���������������������1###############" << endl;
		cout << "###############��ѯ��ǰĳһ��Ȧĳͷ���״̬��Ϣ������2###############" << endl;
		cout << "#####ͳ�Ƶ�ǰ��ÿ��Ʒ��������������ء�����ʱ��ֲ����������3#####" << endl;
		cout << "###########��ѯ��5��������ۼ�¼�����̶��Ĺ����¼������4############" << endl;
		cout << "##########################��ѯ��ǰ��Ȧ������5########################" << endl;
		cout << "############################�˳�������0##############################" << endl;
	}
	Pig_node* p6 = head;
	Save(p6);
}
//��ʾ��ǰ��ÿ��Ʒ��������������ء�����ʱ��ֲ������Ϣ
void f3(Pig_node* head) {
	int black_count(0), small_count(0), big_count(0);
	Pig_node* p4 = head;
	while (p4 != NULL) {
		if(p4->pig_time==0)
			p4=p4->next;
		else {
			if (p4->pig_type == 1)
				black_count++;
			if (p4->pig_type == 2)
				small_count++;
			if (p4->pig_type == 3)
				big_count++;
			p4 = p4->next;
		}
	}
	cout << "*****��ʾ��ǰ��ÿ��Ʒ��������������ء�����ʱ��ֲ������Ϣ*****" << endl;
	cout << "**********�������Ϣ**********" << endl;
	cout << "������������" << black_count << endl;
	Pig_node* p3 = head;
	while (p3 != NULL) {
		if(p3->pig_time==0)
			p3=p3->next;
		else {
			if (p3->pig_type == 1)
				cout << "���������" << p3->pig_weight << '\t' << "�������ʱ�䣺" << p3->pig_time << endl;
			p3 = p3->next;
		}
	}
	cout << "**********С�������Ϣ**********" << endl;
	cout << "С������������" << small_count << endl;
	Pig_node* p5 = head;
	while (p5 != NULL) {
		if(p5->pig_time==0)
			p5=p5->next;
		else {
			if (p5->pig_type == 2)
				cout << "���������" << p5->pig_weight << '\t' << "�������ʱ�䣺" << p5->pig_time << endl;
			p5 = p5->next;
		}
	}
	cout << "**********�󻨰������Ϣ**********" << endl;
	cout << "�󻨰�����������" << big_count << endl;
	Pig_node* p6 = head;
	while (p6 != NULL) {
		if(p6->pig_time==0)
			p6=p6->next;
		else {
			if (p6->pig_type == 3)
				cout << "���������" << p6->pig_weight << '\t' << "�������ʱ�䣺" << p6->pig_time << endl;
			p6 = p6->next;
		}
	}
	cout << "#####��Ҫ����ͳ�Ƶ�ǰ��ÿ��Ʒ��������������ء�����ʱ��ֲ����������1����Ҫ�˳���ǰ��ѯҳ�������������1����#####" << endl;
	int temp1;
	cin >> temp1;
	if (temp1 == 1) {
		Pig_node* p7 = head;
		Pig_node* p8 = head;
		Loop1(p7);
		f3(p8);
	} else {
		cout << "###############��ѯ��ǰĳһ��Ȧ���������������������1###############" << endl;
		cout << "###############��ѯ��ǰĳһ��Ȧĳͷ���״̬��Ϣ������2###############" << endl;
		cout << "#####ͳ�Ƶ�ǰ��ÿ��Ʒ��������������ء�����ʱ��ֲ����������3#####" << endl;
		cout << "###########��ѯ��5��������ۼ�¼�����̶��Ĺ����¼������4############" << endl;
		cout << "##########################��ѯ��ǰ��Ȧ������5#########################" << endl;
		cout << "############################�˳�������0##############################" << endl;
	}
	Pig_node* p9 = head;
	Save(p9);
}
//��ʾ������������ۼ�¼��Ϣ�������ļ�fileOutputsell.txt��
void f4(Pig_node* head) {
	ofstream fileOutputsell;
	fileOutputsell.open("fileOutputsell.txt", ios::out);
	fileOutputsell << "*****��ʾ������������ۼ�¼��Ϣ*****" << endl;
	int five_year = 61;
	for (int i = 1; i <= five_year; i++) {
		Pig_node* p13=head;
		Save(p13);
		int grow_time(0);
		for (; grow_time <= 90; grow_time++) {
			Pig_node* p4 = head;
			while (p4 != NULL) {
				if(p4->pig_time==0)
					p4=p4->next;
				else {
					p4->pig_weight = Addweight(p4->pig_weight);
					p4->pig_time++;
					p4 = p4->next;
				}
			}
		}
		double total_price = 0;
		int black_sold = 0;
		int small_sold = 0;
		int big_sold = 0;
		int black_pig_now = 0;
		int small_pig_now = 0;
		int big_pig_now = 0;
		Pig_node* p8 = head;
		while (p8 != NULL) {
			if(p8->pig_time==0)
				p8=p8->next;
			else {
				if ((p8->pig_weight > 150)|| (p8->pig_time > 365)) {
					switch (p8->pig_type) {
						case(1): {
								total_price = total_price + p8->pig_weight * 15 * 2;
								black_sold++;
								p8->pig_time = 0;
								break;
							}
						case(2): {
								total_price = total_price + p8->pig_weight * 7 * 2;
								small_sold++;
								p8->pig_time = 0;
								break;
							}
						case(3): {
								total_price = total_price + p8->pig_weight * 6 * 2;
								big_sold++;
								p8->pig_time = 0;
								break;
							}
					}
					p8 = p8->next;
				} else p8=p8->next;
			}
		}
		Pig_node* p9 = head;
		while (p9 != NULL) {
			if (p9->pig_time == 0)
				p9=p9->next;
			else  {
				switch (p9->pig_type) {
					case(1): {
							black_pig_now++;
							break;
						}
					case(2): {
							small_pig_now++;
							break;
						}
					case(3): {
							big_pig_now++;
							break;
						}
				}
				p9 = p9->next;
			}
		}
		int black_pig_add = black_sold;
		int small_pig_add = small_sold;
		int big_pig_add = big_sold;
		int black_pig = black_pig_add + black_pig_now;
		int small_pig = small_pig_add + small_pig_now;
		int big_pig = big_pig_add + big_pig_now;
		int black_stynumber = 100 * black_pig / (black_pig + small_pig + big_pig);
		int other_typenumber = 100 - black_stynumber;
		int total_add = black_pig_add + small_pig_add + big_pig_add;
		int temp1 = 0;
		int temp2 = black_stynumber;
		for (int i = 1; i <=black_pig_add ; i++) {
			Pig_node* p10=head;
			while(p10!=NULL) {
				if(p10->pig_time==0&&p10->pig_type==1) {
					p10->pig_weight = getRandData(20, 50);
					p10->pig_time = Time(180, 160);
				}
				p10=p10->next;
			}
		}
		for (int i = 1; i <=small_pig_add ; i++) {
			Pig_node* p11=head;
			while(p11!=NULL) {
				if(p11->pig_time==0&&p11->pig_type==2) {
					p11->pig_weight = getRandData(20, 50);
					p11->pig_time = Time(180, 160);
				}
				p11=p11->next;
			}
		}
		for (int i = 1; i <=big_pig_add ; i++) {
			Pig_node* p12=head;
			while(p12!=NULL) {
				if(p12->pig_time==0&&p12->pig_type==3) {
					p12->pig_weight = getRandData(20, 50);
					p12->pig_time = Time(180, 160);
				}
				p12=p12->next;
			}
		}
		fileOutputsell << "�����������ۼ�Ϊ��" << total_price << '\t' << "������������Ϊ��" << black_sold + small_sold + big_sold << '\t' << "����������ĿΪ��" << black_sold << '\t' << "С����������ĿΪ��" << small_sold << '\t' << "�󻨰���������ĿΪ��" << big_sold << endl;
		fileOutputsell << "���ι�����������Ϊ��" << total_add << '\t' << "�����������ĿΪ��" << black_pig_add << '\t' << "����С��������ĿΪ��" << small_pig_add << '\t' << "����󻨰�������ĿΪ��" << big_pig_add << endl;
		fileOutputsell<<'\n';
	}
	cout << "*****��5��������ۼ�¼�����̶��Ĺ����¼��Ϣ�ѱ������ļ�fileOutputsell.txt��*****" << endl;
	cout << "#####���������ѯ��5��������ۼ�¼�����̶��Ĺ����¼��Ϣ��������1�˳���ǰ��ѯҳ�������������1����#####" << endl;
	int temp3;
	cin >> temp3;
	if (temp3 == 1) {
		Pig_node* p5 = head;
		Pig_node* p6 = head;
		Loop1(p5);
		f4(p6);
	} else {
		cout << "###############��ѯ��ǰĳһ��Ȧ���������������������1###############" << endl;
		cout << "###############��ѯ��ǰĳһ��Ȧĳͷ���״̬��Ϣ������2###############" << endl;
		cout << "#####ͳ�Ƶ�ǰ��ÿ��Ʒ��������������ء�����ʱ��ֲ����������3#####" << endl;
		cout << "###########��ѯ��5��������ۼ�¼�����̶��Ĺ����¼������4############" << endl;
		cout << "##########################��ѯ��ǰ��Ȧ������5########################" << endl;
		cout << "############################�˳�������0##############################" << endl;
	}
	Pig_node* p7 = head;
	Save(p7);
}
//����������ʼ�������Ϣ
Pig_node* Creat() {
	int black_pig, small_pig, big_pig;
	cout << "*****���������С����ʹ󻨰���ĳ�ʼ����*****" << endl;
	cin >> black_pig >> small_pig >> big_pig;
	int total = black_pig + small_pig + big_pig;
	int black_typenumber = 100 * black_pig / total;
	int other_typenember = 100 - black_typenumber;
	int temp1 = 0;
	int temp2 = black_typenumber;
	Pig_node* head = NULL;
	Pig_node* p1 = head;
	Pig_node* p2 = head;
	for (int i = 1; i <= total; i++) {
		p1 = new Pig_node;
		p1->pig_weight = getRandData(20, 50);
		p1->pig_time = Time(180, 160);
		if (i <= black_pig) {
			p1->pig_type = 1;
			if (temp1 == black_typenumber)
				temp1 = 0;
			p1->sty_number = ++temp1;
		} else if (i > black_pig && i <= (black_pig + small_pig)) {
			p1->pig_type = 2;
			if (temp2 == 100)
				temp2 = black_typenumber;
			p1->sty_number = ++temp2;
		} else {
			p1->pig_type = 3;
			if (temp2 == 100)
				temp2 = black_typenumber;
			p1->sty_number = ++temp2;
		}
		if (head == NULL)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
	}
	p1->next = NULL;
	return head;
}
//���ļ�fileOutputsavedata.txt�ж�ȡ���ݲ����
Pig_node* Read() {
	int j = 0;
	double a[10000];
	for (int i = 0; i < 10000; i++)
		a[i] = 0;
	ifstream infile("fileOutputsavedata.txt", ios::in);
	for (int i = 0; !infile.eof(); i++) {
		infile >> a[i];
	}
	Pig_node* head = NULL;
	Pig_node* p1 = head;
	Pig_node* p2 = head;
	for (int i = 1;; i++) {
		if (a[j] == 0)
			break;
		p1 = new Pig_node;
		p1->pig_type = (int)a[j];
		p1->pig_weight = a[j + 1];
		p1->pig_time = (int)a[j + 2];
		p1->sty_number = (int)a[j + 3];
		j = j + 4;
		if (head == NULL)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
	}
	p1->next = NULL;
	return head;
}
int main() {
	Pig_node* head;
	ifstream infile("fileOutputsave.txt", ios::in);
	long double ch;
	ch = infile.get();
	if (ch == EOF)
		head = Creat();
	else {
		cout << infile.rdbuf() << endl;
		head = Read();
	}
	int button;
	cout << "###############��ѯ��ǰĳһ��Ȧ���������������������1###############" << endl;
	cout << "###############��ѯ��ǰĳһ��Ȧĳͷ���״̬��Ϣ������2###############" << endl;
	cout << "#####ͳ�Ƶ�ǰ��ÿ��Ʒ��������������ء�����ʱ��ֲ����������3#####" << endl;
	cout << "###########��ѯ��5��������ۼ�¼�����̶��Ĺ����¼������4############" << endl;
	cout << "#########################��ѯ��ǰ��Ȧ������5#########################" << endl;
	cout << "############################�˳�������0##############################" << endl;
	cin >> button;
	for (; button > 0;)
		if (button == 1) {
			f1(head);
			cin >> button;
			continue;
		} else if (button == 2) {
			f2(head);
			cin >> button;
			continue;
		} else  if (button == 3) {
			f3(head);
			cin >> button;
			continue;
		} else if (button == 4) {
			f4(head);
			cin >> button;
			continue;
		} else if (button == 5) {
			Cout(head);
			cin >> button;
			continue;
		} else if (button == 0) {
			return 0;
		}
}

