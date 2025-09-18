class TaskManager {
    struct Task {
        int priority;
        int taskId;
        int userId;
    };
    
    // Max heap with custom comparator
    struct Compare {
        bool operator()(const Task &a, const Task &b) {
            if (a.priority == b.priority) return a.taskId < b.taskId; // higher taskId first
            return a.priority < b.priority; // higher priority first
        }
    };
    
    priority_queue<Task, vector<Task>, Compare> pq;
    unordered_map<int, pair<int,int>> taskInfo; 
    // taskId -> {userId, priority}
    
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            pq.push({priority, taskId, userId});
            taskInfo[taskId] = {userId, priority};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        pq.push({priority, taskId, userId});
        taskInfo[taskId] = {userId, priority};
    }
    
    void edit(int taskId, int newPriority) {
        auto [userId, oldPriority] = taskInfo[taskId];
        taskInfo[taskId] = {userId, newPriority};
        pq.push({newPriority, taskId, userId}); // push new version
    }
    
    void rmv(int taskId) {
        taskInfo.erase(taskId); // lazy removal
    }
    
    int execTop() {
        while (!pq.empty()) {
            Task top = pq.top();
            pq.pop();
            
            auto it = taskInfo.find(top.taskId);
            if (it != taskInfo.end() && it->second.second == top.priority) {
                // valid task
                int userId = it->second.first;
                taskInfo.erase(it);
                return userId;
            }
        }
        return -1; // no tasks left
    }
};