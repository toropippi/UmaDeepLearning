#include "bits/stdc++.h"
#include <iostream>
#include <fstream>
#include <dirent.h>
using namespace std;

//string folds="";
//string alls[]={"ＫＯ術","アイテム使用強化","ガード強化","ガード性能","キノコ大好き","ジャンプ鉄人","スタミナ急速回復","スタミナ奪取","ひるみ軽減","フルチャージ","ブレ抑制","ボマー","ランナー","火事場力","火属性攻撃強化","火耐性","会心撃【属性】","回避距離ＵＰ","回避性能","回復速度","滑走強化","貫通弾・貫通矢強化","気絶耐性","鬼火纏","逆恨み","逆襲","強化持続","業物","見切り","幸運","広域化","攻めの守勢","攻撃","高速変形","剛刃研磨","散弾・拡散矢強化","死中に活","耳栓","弱点特効","集中","匠","乗り名人","植生学","心眼","水属性攻撃強化","水耐性","睡眠属性強化","睡眠耐性","精霊の加護","早食い","装填拡張","装填速度","速射強化","属性やられ耐性","体術","体力回復量ＵＰ","耐震","弾丸節約","弾導強化","地質学","挑戦者","超会心","通常弾・連射矢強化","泥雪耐性","笛吹き名人","砥石使用高速化","特殊射撃強化","毒属性強化","毒耐性","鈍器使い","納刀術","破壊王","剥ぎ取り鉄人","爆破やられ耐性","爆破属性強化","抜刀術【技】","抜刀術【力】","反動軽減","飛び込み","氷属性攻撃強化","氷耐性","不屈","風圧耐性","腹減り耐性","壁面移動","泡沫の舞","砲術","砲弾装填","防御","麻痺属性強化","麻痺耐性","満足感","陽動","雷属性攻撃強化","雷耐性","龍属性攻撃強化","龍耐性","力の解放","渾身","翔蟲使い","達人芸","NULL"};

vector<string> getpath(){
    vector<string> ss;
    string s;
    DIR *dir;
    struct dirent *dp;
    //char dirpath[] = folds.c_str();
    //folds.c_str()
    dir = opendir("./");
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



int main(){
    vector<string> ss;
    ss=getpath();
    int lpsz=ss.size();
    for(int i=0;i<lpsz;i++)
    {
        int _=remove(ss[i].c_str());
    }
    return 0;
}

