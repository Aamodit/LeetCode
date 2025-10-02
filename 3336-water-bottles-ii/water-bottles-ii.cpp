class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drunk = numBottles; // drink initial bottles
        int empty = numBottles;
        
        while (empty >= numExchange) {
            // exchange empties for 1 full bottle
            empty -= numExchange;
            numExchange++;   // cost increases
            drunk++;         // drink that new full bottle
            empty++;         // it becomes empty again
        }
        
        return drunk;
    }
};
