class Solution {
public:
    bool validUtf8(vector<int>& data) {
        for(int i=0;i<data.size();i++){
            int bytes=0;
            int val=data[i];
            if(val>255){
                return false;
            }
            
            else if((val&128)==0){
                bytes=1;
            }
            
            else if((val&224)==192){
                bytes=2;
            }
            
            else if((val&240)==224){
                bytes=3;
            }
            
            else if((val&248)==240){
                bytes=4;
            }
            else{
                return false;
            }
            
            for(int j=1;j<bytes;j++){
                if(j+i >=data.size())
                    return false;
                else if((data[i+j]&192) != 128){
                    return false;
                }
            }
            
            i+=bytes-1;
        }
        return true;
    }
};