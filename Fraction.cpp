#include<bits/stdc++.h>
using namespace std;

int decimalShift = 0;

void shiftdecimal(string &s);
string reapetingdigit(string &s);
int find(string &s,char c,int index);
bool checkcommon(string &s,int position,int index);
string substring(string &s,int left,int right);
string itos(int n);
string reverse(string &s);
string removedot(string s);
string trimzero(string s);
void findFraction(string &s);

int main(){
	string s;
	cin >> s;
	findFraction(s);
}

void findFraction(string &s){
	shiftdecimal(s);
	string reapeting = reapetingdigit(s);
	string ans = "";
	int rep_idx = s.find(reapeting);
	string nonreapting = trimzero(removedot(substring(s,0,rep_idx + reapeting.size())));
	string numerator = itos(stoi(nonreapting) - stoi(removedot(substring(s,0,rep_idx))));
	int rep_len = reapeting.size();
	string nine="";
	while(rep_len--){
		nine.push_back('9');
	}
	string zero = "";
	decimalShift += (rep_idx - s.find('.') - 1);
	while(decimalShift--){
		zero.push_back('0');
	}
	for(int i=0;i<zero.size();i++){
		nine.push_back(zero[i]);
	}
	string denomenator = nine;
	cout << numerator << "/" << denomenator << endl;
}

void shiftdecimal(string &s){
	bool gotdot = false;
	int initialdot = -1;

	for(int i=0;i<s.size();i++){
		if(gotdot){
			if(s[i] == '0')
				decimalShift++;
		}
		if(s[i] == '.'){
			gotdot = !gotdot;
			initialdot = i;
		}

	}
	int dotmove = decimalShift;
	while(dotmove--){
		swap(s[initialdot],s[initialdot+1]);
		initialdot++;

	}
}

string reapetingdigit(string &s){
	bool gotdot = true;
	for(int i=s.size();i>0;i--){
		if(gotdot){
			int position = find(s,s[i],i-1);
			if(position != -1){
				bool chk = checkcommon(s,position,i);
				if(chk){
					return substring(s,position,i);
				}
			}
		}
		if(s[i] == '.'){
			gotdot = !gotdot;
		}

	}
}

int find(string &s,char c,int index){
	for(int i=index;i>0;i--){
		if(s[i] == c)
			return i;
	}
	return -1;
}

bool checkcommon(string &s,int position,int index){
	int temp = index;
	while(s.size()>index && position<index){
		if(s[position] != s[index])
			return false;
		position++;
		index++;
		if(s.size()<=index && position<temp) return false;
	}
	return true;
}

string substring(string &s,int left,int right){
	string result = "";
	while(left<right){
		result.push_back(s[left]);
		left++;
	}
	return result;
}

string itos(int n){
	string s="";
	while(n>0){
		int last = n%10;
		char c = last + '0';
		s.push_back(c);
		n /=10;
	}
	reverse(s);
	return s;
}

string reverse(string &s){
	int l=0,r=s.size()-1;
	while(l<r){
		swap(s[l],s[r]);
		l++;
		r--;
	}
}

string removedot(string s){
	string s1="";
	for(auto c:s){
		if(c != '.'){
			s1.push_back(c);
		}
	}
	return s1;
}

string trimzero(string s){
	string res = "";
	int l=0;
	int r=s.size()-1;
	while(l<r){
		if(s[l] == '0')
			l++;
		else
			break;
	}
	while(l<r){
		if(s[r] == '0')
			r--;
		else
			break;
	}
	while(l<=r){
		res.push_back(s[l]);
		l++;
	}
	return res;
}