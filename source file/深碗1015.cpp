#include <iostream>
#include <string>

using namespace std;

class GameCharacter {
public:
	string Name;
	int Health; int Cap_Health; int Power;
	int Level;

	GameCharacter() {}
	GameCharacter(string n, int l) { 
		this->Name = n;  this->Level = l; 
		if (l == 1) {
			this->Cap_Health = 100; this->Health = this->Cap_Health;
			this->Power = 150;
		}
		else if (l > 1) {
			this->Cap_Health = ((100 + 125) * 1.5) * 1.2 * l; this->Health = this->Cap_Health;
			this->Power = ((150 + 350) * 2.5) * 1.5 * l;
		}
	}
	~GameCharacter(){}
	void damage(int v) {
		this->Health -= v;
		if (this->Health < 0)  this->Health = 0;
	}
	void heal(int v) {
		this->Health += v;
		if (this->Health > this->Cap_Health) this->Health = this->Cap_Health;
	}
	void levelup() {
		this->Level += 1;
		this->Cap_Health = ((100 + 125) * 1.5) * 1.2 * this->Level;
		this->Power = ((150 + 350) * 2.5) * 1.5 * this->Level;
		this->Health = this->Cap_Health;
	}
	void show() {
		cout << "名字: " << this->Name << endl << "生命值 / 總生命值: " << this->Health << " / " << this->Cap_Health << endl << "等級: " << this->Level << endl << "戰鬥力: " << this->Power << endl;
	}
};


int main() {
	int n;
	cout << "請輸入角色人數: ";
	cin >> n;
	GameCharacter* p = new GameCharacter[n];
	for (int i = 0; i < n; i++) {
		string n; int h; int l;
		cout << "======= 角色 " << i + 1 << " =======" << endl << "名稱: "; 
		cin >> n; 
		cout << "等級: "; 
		cin >> l;
		p[i] = GameCharacter(n, l);
	}
	while (1) {
		int t;
		cout << endl << "======== 選單 ========" << endl << "1. 扣血" << endl << "2. 回血" << endl << "3. 升級" << endl << "4. Show角色資料" << endl << "5. Show全部角色" << endl << "0. 結束程式" << endl << endl << "請選擇: ";
		cin >> t;
		if (n == 1) {
			switch (t) {
			case 1:
				cout << endl;
				int d;
				cout << "輸入傷害值: "; cin >> d;
				cout << endl << "======== 角色1 ========" << endl;
				p[0].damage(d);
				p[0].show();
				break;
			case 2:
				cout << endl;
				int h;
				cout << "輸入回血量: "; cin >> h;
				cout << endl << "======== 角色1 ========" << endl;
				p[0].heal(h);
				p[0].show();
				break;
			case 3:
				cout << endl;
				cout << "角色升級成功!" << endl;
				cout << endl << "======== 角色1 ========" << endl;
				p[0].levelup();
				p[0].show();
				break;
			case 4:
				cout << endl << "======== 角色1 ========" << endl;
				p[0].show();
				break;
			case 5:
				cout << endl << "======== 角色1 ========" << endl;
				p[0].show();
				break;
			case 0:
				return 0;
				break;
			default:
				cout << endl << "請輸入0~5的操作" << endl;
				break;
			}
		}
		else {
			switch (t) {
			case 1:
				cout << endl << "請選擇角色編號 (1~" << n << "): ";
				int a; cin >> a; int d;
				cout << endl << "輸入傷害值: "; cin >> d;
				cout << endl << "======== 角色" << a << " ========" << endl;
				p[a - 1].damage(d);
				p[a - 1].show();
				break;
			case 2:
				cout << endl << "請選擇角色編號 (1~" << n << "): ";
				int b; cin >> b; int h;
				cout << endl << "輸入回血量: "; cin >> h;
				cout << endl << "======== 角色" << b << " ========" << endl;
				p[b - 1].heal(h);
				p[b - 1].show();
				break;
			case 3:
				cout << endl << "請選擇角色編號 (1~" << n << "): ";
				int c; cin >> c;
				cout << endl << "角色升級成功!" << endl << "======== 角色"  << c << " ========" << endl;
				p[c - 1].levelup();
				p[c - 1].show();
				break;
			case 4:
				cout << endl << "請選擇角色編號 (1~" << n << "): ";
				int f; cin >> f;
				cout << endl << "======== 角色" << f << " ========" << endl;
				p[f - 1].show();
				break;
			case 5:
				cout << endl;
				for (int i = 0; i < n; i++) { 
					cout << "======== 角色" << i+1 << " ========" << endl;
					p[i].show(); 
					cout << endl;
				}
				break;
			case 0:
				return 0;
				break;
			default:
				cout << endl << "請輸入0~5的操作" << endl;
				break;
			}
		}
	}
	delete[] p;
	return 0;
}
