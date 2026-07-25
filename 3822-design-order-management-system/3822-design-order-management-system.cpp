class OrderManagementSystem {

    struct Order{
        string type;
        int price;
        Order(string t, int p): type{t}, price{p}{}
    };

    unordered_map<int, Order>m; //orderid->order
    unordered_map<string, unordered_map<int, unordered_set<int>>>m1; //all orderids of type and price
public:
    OrderManagementSystem() {
        
    }
    
    void addOrder(int orderId, string orderType, int price) {
        m.emplace(orderId, Order(orderType, price));
        m1[orderType][price].insert(orderId);
    }
    
    void modifyOrder(int orderId, int newPrice) {
        m1[m.at(orderId).type][m.at(orderId).price].erase(orderId);
        m.at(orderId).price = newPrice;
        m1[m.at(orderId).type][m.at(orderId).price].insert(orderId);
    }
    
    void cancelOrder(int orderId) {
        m1[m.at(orderId).type][m.at(orderId).price].erase(orderId);
        m.erase(orderId);
    }
    
    vector<int> getOrdersAtPrice(string orderType, int price) {
        const auto& orders = m1[orderType][price];
        return vector<int>(orders.begin(), orders.end());
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