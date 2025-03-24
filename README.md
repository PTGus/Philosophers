42 Project : philosophers
# <h1 align="center">philosophers</h1>

# About
The Dining Philosophers Problem is a classic synchronization problem in computer science that demonstrates issues related to process synchronization, resource sharing, and deadlock prevention.

# The Problem
Imagine one or more philosophers sitting at a round table. In front of each philosopher is a plate of food, and between every pair of philosophers is a single fork. To eat, a philosopher needs to pick up two forks (the one on their left and the one on their right).
•The philosophers alternate between eating, thinking, or sleeping:
 ○ While performing an action the philosophers can not perform any other action.


# Challenges
1. Resource Sharing: Only one philosopher can use a fork at a time.
2. Deadlock Risk: If each philosopher picks up the fork on their left at the same time, they will all wait indefinitely for the fork on their right, causing a deadlock.
3. Starvation: Some philosophers may keep eating while others never get a chance, leading to starvation.

# Purpose
This problem helps illustrate and teach key concepts in concurrent programming, including:

• Mutual Exclusion: Ensuring that resources (forks) are used by one philosopher at a time.
• Deadlock Avoidance: Designing algorithms to avoid situations where all processes are stuck waiting.
• Starvation Prevention: Making sure each process (philosopher) eventually gets access to resources.
