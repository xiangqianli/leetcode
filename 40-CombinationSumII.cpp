//
//  39-CombinationSum.cpp
//  leecode
//
//  Created by lixiangqian on 16/10/26.
//  Copyright © 2016年 lixiangqian. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
#include <stdlib.h>
using namespace std;
void combinationSumContinue(vector<vector<int>> &r,vector<int> &tr, vector<int> &candidates,int target,long last){
    bool h= false;
    vector<int>::iterator t = find(candidates.begin(), candidates.end(), target);
    if(t!=candidates.end()&&(t-candidates.begin()<last)){//不可重复
        tr.push_back(*t);
        if(find(r.begin(),r.end(),tr)==r.end())//最后不可重复
            r.push_back(tr);
        h=true;
    }
    if(h)
        tr.pop_back();
    for(int i=0;candidates[i]<target&&i<last;i++){//不可重复
        //回溯算法的核心：push之后要pop
        tr.push_back(candidates[i]);
        target = target-candidates[i];
        combinationSumContinue(r, tr, candidates, target,i);
        target = target+candidates[i];
        tr.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates,int target){
    vector<vector<int>> r;
    long size = candidates.size();
    int temptarget=target;
    sort(candidates.begin(),candidates.end());
    for(long i=size-1;i>=0;i--){
        temptarget = target;
        if(temptarget>=candidates[i]){
            temptarget=temptarget-candidates[i];
            vector<int> tr;
            tr.push_back(candidates[i]);
            if(temptarget>0){
                combinationSumContinue(r,tr,candidates, temptarget, i);
            }else{
                if(find(r.begin(),r.end(),tr)==r.end())//最后不可重复
                    r.push_back(tr);
            }
        }
    }
    return r;
}
int main(){
    vector<int> candidates;
    candidates.push_back(10);
    candidates.push_back(1);
    candidates.push_back(2);
    candidates.push_back(7);
    candidates.push_back(6);
    candidates.push_back(1);
    candidates.push_back(5);

    int target=8;
    vector<vector<int>> r = combinationSum2(candidates,target);
    for(int i=0;i<r.size();i++){
        cout<<"========"<<endl;
        for(int j=0;j<r[i].size();j++){
            cout<<r[i][j]<<endl;
        }
    }
    return 0;
}
