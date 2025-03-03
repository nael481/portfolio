# Popeye

**Description**: POPEYE is a project that will help you master the basics of containerizing applications and defining multi-container infrastructures using Docker and Docker Compose.

**Services**:
1. **Poll (Flask - Python)**
2. **Redis**
3. **Worker (Java)**
4. **PostgreSQL**
5. **Result (Node.js)**

**Docker Configuration**:
- **Poll Dockerfile**: Based on an official Python image.
- **Result Dockerfile**: Based on an official Node.js version 20 Alpine image.
- **Worker Dockerfile**: Uses a multi-stage build.
- **PostgreSQL Dockerfile**: Based on the official PostgreSQL version 16 image.

**Docker Compose**:
- Services: `poll`, `redis`, `worker`, `db`, `result`
- Networks: `poll-tier`, `result-tier`, `back-tier`
- Volume: `db-data`
- Automatic restart