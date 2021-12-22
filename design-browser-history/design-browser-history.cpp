class BrowserHistory {
    vector<string> History;
    int currentIndex = -1;
    int size = 0;
public:
    BrowserHistory(string homepage) {
        visit(homepage);
    }
    
    void visit(string url) {
        currentIndex++;
        if(currentIndex >= size) {
            History.push_back("");
        }
        History[currentIndex] = url;
        size = currentIndex + 1;
    }
    
    string back(int steps) {
        currentIndex = max(0, currentIndex - steps);
        return History[currentIndex];
    }
    
    string forward(int steps) {
        currentIndex = min(size - 1, currentIndex + steps);
        return History[currentIndex];
    }
};
