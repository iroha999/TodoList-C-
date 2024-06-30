#include <iostream>
#include "TodoList.h"

int main() {
    // TodoListのインスタンスを作成
    TodoList todoList;
    std::string command;

    // ユーザーコマンドを受け付ける無限ループを開始
    while(true) {
        // ユーザーにコマンドの入力を促す
        std::cout << "Enter command (add, delete, display, quit): ";
        std::cin >> command;

        // コマンドが "add" の場合
        if(command == "add") {
            std::string task;
            // ユーザーにタスクの入力を促す
            std::cout << "Enter task: ";
            std::cin.ignore();
            std::getline(std::cin, task);
            // タスクをTodoListに追加
            todoList.addTask(task);
        }
        // コマンドが "delete" の場合
        else if(command == "delete") {
            int index;
            // ユーザーに削除するタスク番号の入力を促す
            std::cout << "Enter task number: ";
            std::cin >> index;
            try {
                // TodoListからタスクを削除
                todoList.deleteTask(index - 1);
            } catch(const std::out_of_range& e) {
                // タスク番号が範囲外の場合、エラーメッセージを出力
                std::cout << e.what() << std::endl;
            }
        }
        // コマンドが "display" の場合
        else if(command == "display") {
            if (todoList.isEmpty()) {
                std::cout << "No tasks" << std::endl;
            }
            else {
                // TodoListのタスクを表示
                todoList.displayTasks();
            }
        }
        // コマンドが "quit" の場合
        else if(command == "quit") {
            // ループを抜けてプログラムを終了
            break;
        }
        // コマンドが認識できない場合
        else {
            // エラーメッセージを出力
            std::cout << "Unknown command" << std::endl;
        }
    }

    return 0;
}