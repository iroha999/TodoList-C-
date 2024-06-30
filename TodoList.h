#include <vector>
#include <string>

// TodoListクラスの定義
class TodoList {
public:
    // タスクを追加するメソッド
    // @param task 追加するタスクの内容
    void addTask(const std::string& task) {
        tasks.push_back(task);  // タスクをリストに追加
    }

    // タスクを削除するメソッド
    // @param index 削除するタスクのインデックス
    void deleteTask(int index) {
        if(index < 0 || index >= tasks.size()) {  // インデックスが範囲外の場合
            throw std::out_of_range("Index out of range");  // 例外を投げる
        }
        tasks.erase(tasks.begin() + index);  // タスクをリストから削除
    }

    // 全てのタスクを表示するメソッド
    void displayTasks() const {
        for(int i = 0; i < tasks.size(); ++i) {  // 全てのタスクに対して
            std::cout << i + 1 << ": " << tasks[i] << std::endl;  // タスクを表示
        }
    }

    bool isEmpty() const {
        return tasks.empty();
    }


private:
    std::vector<std::string> tasks;  // タスクを保存するリスト
};