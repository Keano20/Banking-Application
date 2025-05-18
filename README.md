# 💳 Banking Application

A modular, object-oriented C++ banking system that allows users to create and manage accounts via a text-based interface. This project demonstrates the use of key object-oriented principles and integrates multiple design patterns including Factory, Singleton, and Observer.

---

## 📦 Features

- Create savings and current accounts
- Deposit and withdraw funds
- Apply interest to all accounts
- View account summaries
- Transaction logging using the Observer pattern
- Text-based user interface with error handling and input validation

---

## 🧠 Design Patterns Used

### ✅ Factory Pattern
Used in `AccountFactory` to decouple the creation of `Account` objects based on user input.

### ✅ Singleton Pattern
Implemented in `BankManager` to ensure a single point of control for all account operations.

### ✅ Observer Pattern
The `TransactionLogger` observes account operations and logs events such as deposits, withdrawals, and interest applications.

---
