# Route Optimizer Microservice

## Overview

Route Optimizer Microservice is a multi-passenger carpool routing system designed to compute the most efficient travel route while dynamically splitting transportation costs among passengers.

The project combines a C++ optimization engine with a Node.js backend and an interactive web-based frontend to provide real-time route visualization and cost analysis.

The application models the routing problem using concepts inspired by the Travelling Salesman Problem (TSP), evaluating multiple route combinations to determine the minimum-distance travel path.

---

## Features

- Interactive map-based route selection
- Multi-passenger route optimization
- Dynamic fare splitting between passengers
- Real-time route visualization
- Distance matrix generation
- Backend computation using C++
- REST API communication between frontend and backend
- Hybrid architecture using C++ and Node.js

---

## Tech Stack

### Frontend
- HTML
- Tailwind CSS
- Leaflet.js

### Backend
- Node.js
- Express.js

### Optimization Engine
- C++
- STL

---

## System Architecture

Frontend Interface  
↓  
Node.js Express Server  
↓  
C++ Optimization Engine  
↓  
Optimized Route and Fare Distribution

---

## How It Works

1. The user places:
   - Driver starting location
   - Office destination
   - Passenger pickup points

2. The frontend computes pairwise distances between all nodes using geographic coordinates.

3. A distance matrix is generated and sent to the backend server.

4. The Node.js server forwards the optimization data to the C++ computation engine.

5. The optimization engine evaluates possible routing sequences and determines the minimum-distance path.

6. The optimized route and fare distribution are returned to the frontend and displayed on the interactive map.

---

## Project Structure

```text
route-optimizer/
│
├── index.html
├── server.js
├── optimizer.cpp
├── package.json
├── package-lock.json
├── README.md
└── .gitignore
```

---

## Installation and Setup

### Clone Repository

```bash
git clone https://github.com/YOUR_USERNAME/route-optimizer.git
cd route-optimizer
```

### Install Dependencies

```bash
npm install
```

### Compile the C++ Optimization Engine

```bash
g++ optimizer.cpp -o optimizer
```

### Run the Server

```bash
node server.js
```

### Open Application

Visit:

```text
http://localhost:3000
```

---

## Future Improvements

- Held-Karp Dynamic Programming optimization
- Integration with real-world traffic APIs
- Multi-vehicle route optimization
- User authentication system
- Persistent trip history
- Deployment on cloud infrastructure

---

## Learning Outcomes

This project helped in understanding:

- Graph-based optimization problems
- Backend and frontend integration
- REST API communication
- Hybrid system architecture
- Algorithmic route computation
- Practical use of C++ with web technologies

---

## License

This project was developed for educational and learning purposes.