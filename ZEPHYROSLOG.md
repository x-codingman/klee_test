## How to run symbolic execution on zephyr os
### Challenges
* build system, we customize the build system to only focus on the zephyr os API.
* under-constraint parameters check, e.g., we need initialize the necessary kernel objects before the checking.

### Solutions
