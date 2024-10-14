import tkinter as tk
from tkinter import messagebox, simpledialog

class TodoApp:
    def __init__(self, root):
        self.root = root
        self.root.title("To-Do List ")

        # Create a frame for the listbox and scrollbar
        frame = tk.Frame(self.root)
        frame.pack(pady=10)

        # Create the listbox
        self.todo_listbox = tk.Listbox(frame, width=50, height=10, selectmode=tk.SINGLE)
        self.todo_listbox.pack(side=tk.LEFT)

        # Create a scrollbar
        self.scrollbar = tk.Scrollbar(frame)
        self.scrollbar.pack(side=tk.RIGHT, fill=tk.Y)

        # Attach the scrollbar to the listbox
        self.todo_listbox.config(yscrollcommand=self.scrollbar.set)
        self.scrollbar.config(command=self.todo_listbox.yview)

        # Entry box to add new tasks
        self.task_entry = tk.Entry(self.root, width=52)
        self.task_entry.pack(pady=10)

        # Buttons to add, update, delete and clear tasks
        button_frame = tk.Frame(self.root)
        button_frame.pack(pady=20)

        self.add_task_button = tk.Button(button_frame, text="Add Task", command=self.add_task)
        self.add_task_button.pack(side=tk.LEFT)

        self.update_task_button = tk.Button(button_frame, text="Update Task", command=self.update_task)
        self.update_task_button.pack(side=tk.LEFT)

        self.delete_task_button = tk.Button(button_frame, text="Delete Task", command=self.delete_task)
        self.delete_task_button.pack(side=tk.LEFT)

        self.clear_tasks_button = tk.Button(button_frame, text="Clear All Tasks", command=self.clear_tasks)
        self.clear_tasks_button.pack(side=tk.LEFT)

    def add_task(self):
        task = self.task_entry.get()
        if task != "":
            self.todo_listbox.insert(tk.END, task)
            self.task_entry.delete(0, tk.END)
        else:
            messagebox.showwarning("Warning", "You must enter a task.")

    def update_task(self):
        try:
            selected_index = self.todo_listbox.curselection()[0]
            current_task = self.todo_listbox.get(selected_index)
            new_task = simpledialog.askstring("Update Task", "Edit your task:", initialvalue=current_task)
            if new_task:
                self.todo_listbox.delete(selected_index)
                self.todo_listbox.insert(selected_index, new_task)
            else:
                messagebox.showwarning("Warning", "Task cannot be empty.")
        except IndexError:
            messagebox.showwarning("Warning", "You must select a task to update.")

    def delete_task(self):
        try:
            selected_index = self.todo_listbox.curselection()[0]
            self.todo_listbox.delete(selected_index)
        except IndexError:
            messagebox.showwarning("Warning", "You must select a task to delete.")

    def clear_tasks(self):
        if messagebox.askyesno("Clear All Tasks", "Are you sure you want to clear all tasks?"):
            self.todo_listbox.delete(0, tk.END)

if __name__ == "__main__":
    root = tk.Tk()
    todo_app = TodoApp(root)
    root.mainloop()
