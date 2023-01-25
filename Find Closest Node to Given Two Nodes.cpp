/*
Link to the "Find Closest Node to Given Two Nodes" Problem ==>>  https://leetcode.com/problems/find-closest-node-to-given-two-nodes/     
   
Link to the complete Explaination Video ==>> https://youtu.be/OjJd87AJXtQ

*/

class Solution {
public:
    pair<int, int> fun(vector<int>&edges, int node1, int node2){

        unordered_map<int, int > mp;
        int n=edges.size();
        vector<int> visi1(n+2, 0);
        vector<int> visi2(n+2, 0);
        mp[node1]=0;
        int len=0;
        while(edges[node1]!=-1 && visi1[node1]!=1){
            visi1[node1]=1;  
            node1=edges[node1];
            mp[node1]=len++;
        }
        pair<int , int> p1=make_pair(INT_MAX,-1);
        if(mp.find(node2)!=mp.end()){
             p1=make_pair(mp[node2], node2 );
            return p1;
        }
        while(edges[node2]!=-1 && visi2[node2]!=1){

            visi2[node2]=1;
            node2=edges[node2];
            if(mp.find(node2)!=mp.end()){
                p1=make_pair(mp[node2], node2 );
                return p1;
            }
        }
        return p1;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {

        pair<int ,int> p1=fun(edges, node1, node2);
        pair<int, int> p2=fun(edges, node2, node1);
        if(p1.second!=-1  && p1.first<p2.first)
            return p1.second;
        else if( p2.second!=-1 && p2.first<p1.first)
            return p2.second;
        else if(p1.first==p2.first){
            if(p1.second<p2.second)
                return p1.second;
            else
                return p2.second;
        }
        return -1;
    }
   
};
