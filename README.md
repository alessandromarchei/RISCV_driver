
# RISCV Driver Project

This repository contains various resources, algorithms, scripts, and documentation related to RISC-V development. The structure has been carefully organized to support modularity, reusability, and clarity for future contributors.

---

## **Project Structure**

Below is an overview of the repository's directory structure and its contents:

```
.
├── algorithms
│   ├── Caesar
│   └── RSA
├── bash
├── cross_compiler howto.txt
├── Driver
│   ├── Driver_original_stuff
│   ├── full_files
│   └── students_files
├── Screenshots
├── README.md
└── test gcc.txt
```

Each folder is designed to address a specific aspect of the project:

### **1. Algorithms**
This folder contains cryptographic algorithms implemented in C. 
- **`Caesar`**: A simple substitution cipher.
  - `crypto.c`: Implementation of encryption and decryption logic.
  - `crypto.h`: Header file for the Caesar cipher.
- **`RSA`**: An implementation of the RSA cryptosystem.
  - `main.c`: Main program logic for encryption and decryption.
  - `bin`, `obj`: Build outputs and dependencies.
  - `.cbp`, `.depend`, `.layout`: Configuration files for code compilation and structure.

### **2. bash**
Contains Bash scripts to streamline encryption and decryption processes.
- `encrypt_v01.sh`: Automates the encryption process for Caesar and RSA algorithms.
- `decrypt_v01.sh`: Automates decryption, simplifying testing and usability.

### **3. cross_compiler howto.txt**
A guide detailing the steps to configure and use a cross-compiler for RISC-V. This file is particularly useful for setting up a cross-compilation environment to test RISC-V programs on non-RISC-V systems.

### **4. Driver**
This folder encapsulates the RISC-V driver code in three variations:
- **`Driver_original_stuff`**:
  - Contains the original driver files and modules (`lmmodule.c`, `lmmodule.h`) along with a `Makefile` for compilation.
  - Includes build artifacts (`.ko`, `.o`) and test scripts.
  - The `driver_howto.txt` provides instructions for setting up and testing the driver.
- **`full_files`**: Refactored driver implementation with additional features.
- **`students_files`**: A minimal version of the driver code for student testing and learning.

### **5. Screenshots**
A folder for storing visual resources, such as screenshots of test results.
- Example: `test_1.png`, which showcases the results of a specific test.

### **6. test gcc.txt**
This file includes notes or output logs from testing GCC configurations and compilation for RISC-V-related projects.

---

## **Getting Started**

To get started with the repository:

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/alessandromarchei/RISCV_driver.git
   ```

2. **Install the RISC-V Toolchain**:
   Follow the steps below to install and configure the toolchain:
   - Clone the official toolchain:
     ```bash
     git clone https://github.com/riscv/riscv-gnu-toolchain
     ```
   - Install dependencies:
     ```bash
     sudo apt-get install autoconf automake autotools-dev curl python3 python3-pip libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev ninja-build git cmake libglib2.0-dev
     ```
   - Build and install:
     ```bash
     mkdir /opt/riscv
     cd riscv-gnu-toolchain
     ./configure --prefix=/opt/riscv
     make linux
     ```

3. **Compile and Test the Driver**:
   - Navigate to the `Driver` directory:
     ```bash
     cd Driver/full_files
     ```
   - Compile the driver:
     ```bash
     make
     ```
   - Load and test the driver using the provided instructions in `driver_howto.txt`.

---

## **Motivations for Design Choices**

- **Modularity**: Each folder is dedicated to a specific domain (e.g., algorithms, drivers), allowing for easier maintenance and scalability.
- **Algorithm Implementation**: The inclusion of both Caesar and RSA cryptosystems serves as an educational tool and as practical examples for RISC-V applications.
- **Driver Development**: By providing multiple variations (`original`, `full_files`, `students_files`), we support a range of use cases from basic learning to advanced testing.
- **Cross-Compilation**: Necessary for ensuring compatibility with RISC-V systems, especially for environments where direct RISC-V execution is not feasible.

---

## **Contributions**

We welcome contributions to enhance the repository, including:
- Improvements to the algorithms.
- New driver features.
- Additional documentation or tutorials.

Feel free to submit pull requests or open issues for discussions.

---

## **Contact**

For any questions or feedback, please contact the repository maintainer:  
**Alessandro Marchei**  
[GitHub Profile](https://github.com/alessandromarchei)

---

## **License**

This project is licensed under the MIT License. See the `LICENSE` file for details.
