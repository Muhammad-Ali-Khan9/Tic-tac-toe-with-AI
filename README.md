# Tic-Tac-Toe with AI (ANN) - C++

This project is a **Tic-Tac-Toe game** implemented entirely in **C++**, featuring an **AI opponent powered by an Artificial Neural Network (ANN)** written from scratch in C++.  
The project is designed to help learners **understand Object-Oriented Programming (OOP) concepts** while also learning how to build a simple ANN.

---

## 📌 Features

- **Playable Tic-Tac-Toe Game**: Classic 3x3 grid game.  
- **AI Opponent using ANN (C++)**: ANN is fully implemented in C++ without external ML libraries.  
- **Object-Oriented Design**: Demonstrates **Encapsulation, Inheritance, Polymorphism, and Abstraction**.  
- **Two Modes**:  
  - Player vs Player  
  - Player vs AI  
- **Modular Code**: ANN, game logic, and players are fully separated.

---

## 🏗 OOP Concepts Demonstrated

1. **Classes and Objects**
   - Classes: `Game`, `Board`, `Player`, `AIPlayer`, `NeuralNetwork`.
   - Objects represent players, the game board, and ANN.

2. **Encapsulation**
   - Board state, weights, and neuron activations are hidden inside their respective classes.

3. **Inheritance**
   - `AIPlayer` inherits from the `Player` class.

4. **Polymorphism**
   - `makeMove()` behaves differently for human players and AI players.

5. **Abstraction**
   - Complex ANN logic is encapsulated in the `NeuralNetwork` class, exposing only high-level methods like `predictMove()`.

---

## 🧠 AI (ANN) Logic

The **Artificial Neural Network** is implemented entirely in C++.  

### How it works:
- **Feedforward Network**:  
  - Input Layer: Represents the 9 Tic-Tac-Toe board cells.  
  - Hidden Layer(s): Process features using activation functions.  
  - Output Layer: Predicts the best cell to mark.  
- **Activation Function**: Sigmoid or ReLU (configurable).  
- **Weights & Biases**: Randomly initialized and adjusted (optional training).  
- **Decision-making**: Chooses the move with the highest predicted score.

---

## 🚀 Getting Started

### 1️⃣ Prerequisites
- C++ Compiler (g++ or clang++)
- Basic understanding of OOP and ANN fundamentals

### 2️⃣ Build and Run
```bash
# Clone repository
git clone https://github.com/yourusername/tic-tac-toe-ai.git
cd tic-tac-toe-ai

# Build using Makefile
make

# Run
./tic-tac-toe-ai
```

