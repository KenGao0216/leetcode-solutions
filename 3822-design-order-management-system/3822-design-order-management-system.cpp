class OrderManagementSystem {
public:
    unordered_map<string, unordered_map<int,unordered_set<int>>>m;
    unordered_map<int,pair<string, int>>side;
    OrderManagementSystem() {
        
    }
    
    void addOrder(int orderId, string orderType, int price) {
        m[orderType][price].insert(orderId);
        side[orderId] = {orderType, price};

    }
    
    void modifyOrder(int orderId, int newPrice) {
        string type = side[orderId].first;
        int price = side[orderId].second;
        m[type][price].erase(orderId);
        m[type][newPrice].insert(orderId);
        side[orderId].second = newPrice;
    }
    
    void cancelOrder(int orderId) {
        string type = side[orderId].first;
        int price = side[orderId].second;
        m[type][price].erase(orderId);
    }
    
    vector<int> getOrdersAtPrice(string orderType, int price) {
        return vector<int>(m[orderType][price].begin(), m[orderType][price].end());
    }
};

/**
 * Your OrderManagementSystem object will be instantiated and called as such:
 * OrderManagementSystem* obj = new OrderManagementSystem();
 * obj->addOrder(orderId,orderType,price);
 * obj->modifyOrder(orderId,newPrice);
 * obj->cancelOrder(orderId);
 * vector<int> param_4 = obj->getOrdersAtPrice(orderType,price);
 */