#include<iostream>//ofstream头文件 
#include <fstream>
#include<cstdlib>//rand函数的头文件 
#include<cmath>//pow函数的头文件 
using namespace std;
struct Pig_node {
	int sty_number;
	int pig_type;
	double pig_weight;
	int pig_time;
	Pig_node* next;
};
//产生浮点型随机数初始化猪的体重信息
double getRandData(int min, int max) {
	double m1 = (double)(rand() % 101) / 101;                  // 计算 0，1之间的随机小数,得到的值域近似为(0,1)
	min++;                                                     //将 区间变为(min+1,max),
	double m2 = (double)((rand() % (max - min + 1)) + min);    //计算 min+1,max 之间的随机整数，得到的值域为[min+1,max]
	m2 = m2 - 1;
	double dSrc = m1 + m2;
	int iBit = 1;
	double retVal = 0.0;
	int  intTmp = 0;
	intTmp = (int)((dSrc + 0.5 / pow(10.0, iBit)) * pow(10.0, iBit));
	retVal = (double)intTmp / pow(10.0, iBit);
	return retVal;
}
//产生整型随机数初始化猪的生长时间
int Time(int high, int low) {
	return rand() % (high - low + 1) + low;
}
//刷新猪的体重信息函数
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
//将猪的相关信息存入文件fileOutputsave.txt中
void Save(Pig_node* head) {
	ofstream fileOutputsave;
	ofstream fileOutputsavedata;
	fileOutputsave.open("fileOutputsave.txt", ios::out);
	fileOutputsavedata.open("fileOutputsavedata.txt", ios::out);
	fileOutputsave << "*****显示猪圈的详细信息*****" << endl;
	Pig_node* p3 = head;
	while (p3 != NULL) {
		if (p3->pig_time == 0)
			p3 = p3->next;
		else {
			fileOutputsave << "猪的种类：";
			switch (p3->pig_type) {
				case(1): {
						fileOutputsave << "  黑猪  ";
						fileOutputsavedata << 1 << endl;
						break;
					}
				case(2): {
						fileOutputsave << " 小花猪 ";
						fileOutputsavedata << 2 << endl;
						break;
					}
				case(3): {
						fileOutputsave << "大花白猪";
						fileOutputsavedata << 3 << endl;
						break;
					}
			}
			fileOutputsave << "     " << "猪的重量：" << p3->pig_weight << "     " << "猪的生长时间：" << p3->pig_time << "     " << "猪圈编号：" << p3->sty_number << endl;
			fileOutputsavedata << p3->pig_weight << endl << p3->pig_time << endl << p3->sty_number << endl;
			p3 = p3->next;
		}
	}
}
//遍历链表，刷新猪的相关信息
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
//输出猪的信息
void Cout(Pig_node* head) {
	cout << "*****显示猪圈的详细信息*****" << endl;
	Pig_node* p4 = head;
	while (p4 != NULL) {
		if(p4->pig_time==0)
			p4 = p4->next;
		else {
			cout << "猪的种类：";
			switch (p4->pig_type) {
				case(1): {
						cout << "  黑猪  ";
						break;
					}
				case(2): {
						cout << " 小花猪 ";
						break;
					}
				case(3): {
						cout << "大花白猪";
						break;
					}
			}
			cout << '\t' << "猪的重量：" << p4->pig_weight << '\t' << "猪的生长时间：" << p4->pig_time << '\t' << "猪圈编号：" << p4->sty_number << endl;
			p4=p4->next;
		}

	}
	cout << "#####若要继续查询当前猪圈信息请输入1，若要退出当前查询页面请输入任意非1数字#####" << endl;
	int temp1;
	cin >> temp1;
	if (temp1 == 1) {
		Pig_node* p3 = head;
		Pig_node* p5 = head;
		Loop1(p3);
		Cout(p5);
	} else {
		cout << "###############查询当前某一猪圈的猪的数量和种类请输入1###############" << endl;
		cout << "###############查询当前某一猪圈某头猪的状态信息请输入2###############" << endl;
		cout << "#####统计当前猪场每个品种猪的数量和体重、饲养时间分布情况请输入3#####" << endl;
		cout << "###########查询近5年猪的销售记录和猪崽儿的购入记录请输入4############" << endl;
		cout << "##########################查询当前猪圈请输入5#########################" << endl;
		cout << "############################退出请输入0##############################" << endl;
	}
	Pig_node* p6 = head;
	Save(p6);
}
//显示当前某一猪圈的猪的数量和种类信息
void f1(Pig_node* head) {
	int query_sty_number;
	int black_count(0), small_count(0), big_count(0), total_count(0);
	cout << "*****显示当前某一猪圈的猪的数量和种类信息*****" << endl;
	cout << "*****请输入要查询的猪圈编号*****" << endl;
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
	cout << "猪圈编号为" << query_sty_number << "的猪的总数量为：" << total_count << '\t' << "黑猪数量为：" << black_count << '\t' << "小花猪数量为：" << small_count << '\t' << "大花白猪数量：" << big_count << endl;
	cout << "#####如需继续查询某一猪圈的猪的数量和种类信息若请输入1退出当前查询页面请输入任意非1数字#####" << endl;
	int temp1;
	cin >> temp1;
	if (temp1 == 1) {
		Pig_node* p3 = head;
		Pig_node* p5 = head;
		Loop1(p3);
		f1(p5);
	} else {
		cout << "###############查询当前某一猪圈的猪的数量和种类请输入1###############" << endl;
		cout << "###############查询当前某一猪圈某头猪的状态信息请输入2###############" << endl;
		cout << "#####统计当前猪场每个品种猪的数量和体重、饲养时间分布情况请输入3#####" << endl;
		cout << "###########查询近5年猪的销售记录和猪崽儿的购入记录请输入4############" << endl;
		cout << "##########################查询当前猪圈请输入5########################" << endl;
		cout << "############################退出请输入0##############################" << endl;
	}
	Pig_node* p6 = head;
	Save(p6);
}
//显示当前某一猪圈某头猪的状态信息
void f2(Pig_node* head) {
	int query_sty_number;
	cout << "*****显示当前某一猪圈某头猪的状态信息*****" << endl;
	cout << "*****请输入要查询的猪圈编号*****" << endl;
	cin >> query_sty_number;
	cout << "猪圈编号为" << query_sty_number << "的猪圈的猪的信息如下：" << endl;
	Pig_node* p4 = head;
	while (p4 != NULL) {
		if(p4->pig_time==0)
			p4=p4->next;
		else {
			if (p4->sty_number == query_sty_number) {
				cout << "猪的种类：";
				switch (p4->pig_type) {
					case(1): {
							cout << "  黑猪  ";
							break;
						}
					case(2): {
							cout << " 小花猪 ";
							break;
						}
					case(3): {
							cout << "大花白猪";
							break;
						}
				}
				cout << '\t' << "猪的重量：" << p4->pig_weight << '\t' << "猪的生长时间：" << p4->pig_time << endl;
			}
			p4 = p4->next;
		}
	}
	cout << "#####如需继续查询猪圈某头猪的状态信息请输入1若退出当前查询页面请输入任意非1数字#####" << endl;
	int temp1;
	cin >> temp1;
	if (temp1 == 1) {
		Pig_node* p3 = head;
		Pig_node* p5 = head;
		Loop1(p3);
		f2(p5);
	} else {
		cout << "###############查询当前某一猪圈的猪的数量和种类请输入1###############" << endl;
		cout << "###############查询当前某一猪圈某头猪的状态信息请输入2###############" << endl;
		cout << "#####统计当前猪场每个品种猪的数量和体重、饲养时间分布情况请输入3#####" << endl;
		cout << "###########查询近5年猪的销售记录和猪崽儿的购入记录请输入4############" << endl;
		cout << "##########################查询当前猪圈请输入5########################" << endl;
		cout << "############################退出请输入0##############################" << endl;
	}
	Pig_node* p6 = head;
	Save(p6);
}
//显示当前猪场每个品种猪的数量和体重、饲养时间分布情况信息
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
	cout << "*****显示当前猪场每个品种猪的数量和体重、饲养时间分布情况信息*****" << endl;
	cout << "**********黑猪的信息**********" << endl;
	cout << "黑猪总数量：" << black_count << endl;
	Pig_node* p3 = head;
	while (p3 != NULL) {
		if(p3->pig_time==0)
			p3=p3->next;
		else {
			if (p3->pig_type == 1)
				cout << "猪的重量：" << p3->pig_weight << '\t' << "猪的生长时间：" << p3->pig_time << endl;
			p3 = p3->next;
		}
	}
	cout << "**********小花猪的信息**********" << endl;
	cout << "小花猪总数量：" << small_count << endl;
	Pig_node* p5 = head;
	while (p5 != NULL) {
		if(p5->pig_time==0)
			p5=p5->next;
		else {
			if (p5->pig_type == 2)
				cout << "猪的重量：" << p5->pig_weight << '\t' << "猪的生长时间：" << p5->pig_time << endl;
			p5 = p5->next;
		}
	}
	cout << "**********大花白猪的信息**********" << endl;
	cout << "大花白猪总数量：" << big_count << endl;
	Pig_node* p6 = head;
	while (p6 != NULL) {
		if(p6->pig_time==0)
			p6=p6->next;
		else {
			if (p6->pig_type == 3)
				cout << "猪的重量：" << p6->pig_weight << '\t' << "猪的生长时间：" << p6->pig_time << endl;
			p6 = p6->next;
		}
	}
	cout << "#####若要继续统计当前猪场每个品种猪的数量和体重、饲养时间分布情况请输入1，若要退出当前查询页面请输入任意非1数字#####" << endl;
	int temp1;
	cin >> temp1;
	if (temp1 == 1) {
		Pig_node* p7 = head;
		Pig_node* p8 = head;
		Loop1(p7);
		f3(p8);
	} else {
		cout << "###############查询当前某一猪圈的猪的数量和种类请输入1###############" << endl;
		cout << "###############查询当前某一猪圈某头猪的状态信息请输入2###############" << endl;
		cout << "#####统计当前猪场每个品种猪的数量和体重、饲养时间分布情况请输入3#####" << endl;
		cout << "###########查询近5年猪的销售记录和猪崽儿的购入记录请输入4############" << endl;
		cout << "##########################查询当前猪圈请输入5#########################" << endl;
		cout << "############################退出请输入0##############################" << endl;
	}
	Pig_node* p9 = head;
	Save(p9);
}
//显示近五年猪的销售记录信息，存入文件fileOutputsell.txt中
void f4(Pig_node* head) {
	ofstream fileOutputsell;
	fileOutputsell.open("fileOutputsell.txt", ios::out);
	fileOutputsell << "*****显示近五年猪的销售记录信息*****" << endl;
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
		fileOutputsell << "本次卖猪总售价为：" << total_price << '\t' << "本次卖猪总数为：" << black_sold + small_sold + big_sold << '\t' << "黑猪卖出数目为：" << black_sold << '\t' << "小花猪卖出数目为：" << small_sold << '\t' << "大花白猪卖出数目为：" << big_sold << endl;
		fileOutputsell << "本次购入猪崽总数为：" << total_add << '\t' << "购入黑猪崽数目为：" << black_pig_add << '\t' << "购入小花猪崽数目为：" << small_pig_add << '\t' << "购入大花白猪崽数目为：" << big_pig_add << endl;
		fileOutputsell<<'\n';
	}
	cout << "*****近5年猪的销售记录和猪崽儿的购入记录信息已保存在文件fileOutputsell.txt中*****" << endl;
	cout << "#####如需继续查询近5年猪的销售记录和猪崽儿的购入记录信息若请输入1退出当前查询页面请输入任意非1数字#####" << endl;
	int temp3;
	cin >> temp3;
	if (temp3 == 1) {
		Pig_node* p5 = head;
		Pig_node* p6 = head;
		Loop1(p5);
		f4(p6);
	} else {
		cout << "###############查询当前某一猪圈的猪的数量和种类请输入1###############" << endl;
		cout << "###############查询当前某一猪圈某头猪的状态信息请输入2###############" << endl;
		cout << "#####统计当前猪场每个品种猪的数量和体重、饲养时间分布情况请输入3#####" << endl;
		cout << "###########查询近5年猪的销售记录和猪崽儿的购入记录请输入4############" << endl;
		cout << "##########################查询当前猪圈请输入5########################" << endl;
		cout << "############################退出请输入0##############################" << endl;
	}
	Pig_node* p7 = head;
	Save(p7);
}
//创建链表，初始化猪的信息
Pig_node* Creat() {
	int black_pig, small_pig, big_pig;
	cout << "*****请输入黑猪、小花猪和大花白猪的初始数量*****" << endl;
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
//从文件fileOutputsavedata.txt中读取数据并输出
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
	cout << "###############查询当前某一猪圈的猪的数量和种类请输入1###############" << endl;
	cout << "###############查询当前某一猪圈某头猪的状态信息请输入2###############" << endl;
	cout << "#####统计当前猪场每个品种猪的数量和体重、饲养时间分布情况请输入3#####" << endl;
	cout << "###########查询近5年猪的销售记录和猪崽儿的购入记录请输入4############" << endl;
	cout << "#########################查询当前猪圈请输入5#########################" << endl;
	cout << "############################退出请输入0##############################" << endl;
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

