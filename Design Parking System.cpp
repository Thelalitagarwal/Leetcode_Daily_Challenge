/*
Link to the " Design Parking System " Problem ==>> https://leetcode.com/problems/design-parking-system/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/f6AX-JRNRGE

*/

class ParkingSystem {
public:
    int b; int m; int s;

    ParkingSystem(int big, int medium, int small) {
        b=big; m=medium; s=small;
    }
    
    bool addCar(int carType) {
        
        if(carType==1 && b>0){
            b--; return true;
        }
        if(carType==2 && m>0){
            m--; return true;
        }
        if(carType==3 && s>0){
            s--; return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */