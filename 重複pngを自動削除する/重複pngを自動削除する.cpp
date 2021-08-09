#include "bits/stdc++.h"
#include <iostream>
#include <fstream>
#include <dirent.h>
using namespace std;

#define REP(i, n) for(ll i = 0;i < n;i++)
#define ll long long
#define MOD 1000000007LL
//#define MOD 998244353LL
using vi = vector<ll>; // intの1次元の型に vi という別名をつける
using vvi = vector<vi>; // intの2次元の型に vvi という別名をつける
using vvvi = vector<vvi>; // intの2次元の型に vvi という別名をつける
const ll llMAX=stoll("9223372036854775807LL");
const ll llMIN=stoll("-9223372036854775808LL");

//ローリングハッシュ
const __uint128_t HASH_P=2013265921LL*1811939329LL;
const __uint128_t HASH_Wn=52278*59189LL;
const ll HASH_P2=998244353LL;
const ll HASH_Wn2=2LL;


using pr = pair<__uint128_t,int>;
map<pr, int> nums;
map<ll, int> nums2;


//__int128_tのcout関数
ostream &operator<<(ostream &dest, __uint128_t value) {
  ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(ios_base::badbit);
    }
  }
  return dest;
}


vector<string> getpath(){
    vector<string> ss;
    string s;
    DIR *dir;
    struct dirent *dp;
    char dirpath[] = "./";
    dir = opendir(dirpath);
    if (dir == NULL) { return ss; }

    dp = readdir(dir);
    while (dp != NULL) {
        s=string(dp->d_name);
        //printf("%s\n", dp->d_name);
        dp = readdir(dir);
        if (s.size()<=4)continue;
        if (s.substr(s.size()-4,4)==".png"){
          ss.push_back(s);
        }
    }
    if (dir != NULL) { closedir(dir); }
    return ss;
}


int mainloop(string outfile)
{
    //char outfile[] = "file.txt";  //読み込むファイルの指定
    ifstream fin( outfile.c_str(), ios::in | ios::binary );
    //  ファイルを開く
    //  ios::in は読み込み専用  ios::binary はバイナリ形式

    if (!fin){
        cout << "ファイルが開けません";
        return 1;
    }
    //  ファイルが開けなかったときの対策
    
    unsigned char d=0;  //文字列ではないデータ
    __uint128_t h=0,wi=1;
    ll h2=0,wi2=1;

    int idxcnt=0;
    while(!fin.eof()){  //ファイルの最後まで続ける
        h=(h+(__uint128_t)(d)*wi)%HASH_P;
        wi=wi*HASH_Wn%HASH_P;
        
        h2=(h2+(ll)(d)*wi2)%HASH_P2;
        wi2=wi2*HASH_Wn2%HASH_P2;

        fin.read( (char*)&d, sizeof(char) );
        //文字列ではないデータを読みこむ
        idxcnt++;
    }

    fin.close();  //ファイルを閉じる
    //cout<<idxcnt<<endl;
    //cout<<h<<endl;
    pr pr_=make_pair(h,idxcnt);
    nums[pr_]++;
    nums2[h2]++;
    
    if (nums[pr_]!=1)
    {
      if (nums2[h2]==1)
      {
        cout<<"DAMEDESU!!!!!!!!!!!!"<<endl;
      }else{
        int _=remove(outfile.c_str());
      }
      
    }
    return 0;
}


int main(){
    vector<string> ss;
    ss=getpath();
    //if (nums.find(key)!=nums_x.end())//keyのあるなし
    int lpsz=ss.size();

    for(int i=0;i<lpsz;i++)
    {
      //cout<<ss[i]<<endl;
      int ret=mainloop(ss[i]);
      if (ret!=0)return ret;
      if (i%20000==0){
        cout<<"progress="<<i<<"/"<<lpsz<<endl;
      }
    }
    return 0;
}

