#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cassert>

#include "Dlist.h"
#include "Instr.h"

using namespace std;

const int MEMORY_SIZE = 16;

// EFFECTS: initialize the operand stack according to input
void stack_init(Dlist<int> &stack, int num_op) {
    for (int i = 0; i < num_op; ++i) {
        int temp;
        cin >> temp;
        auto operand = new int(temp);
        stack.insertBack(operand);
    }
}

// EFFECTS: initialize the instruction queue according to input
void queue_init(Dlist<Instr> &queue, int num_inst) {
    for (int i = 0; i < num_inst; ++i) {
        Instr temp{};
        cin >> temp;
        auto instruction = new Instr(temp);
        queue.insertBack(instruction);
    }
}

// EFFECTS: initialize the memory array according to input
void mem_init(int memory[]) {
    for (int i = 0; i < MEMORY_SIZE; ++i) {
        cin >> memory[i];
    }
}

// EFFECTS: pop up two elements from the stack and then
//          push the sum of these two elements into the stack
void add(Dlist<int> &operands) {
    int *num1 = operands.removeBack();
    int *num2 = operands.removeBack();
    int rslt = *num1 + *num2;
    delete num1;
    delete num2;
    auto temp = new int(rslt);
    operands.insertBack(temp);
}

// EFFECTS: pop up two elements from the stack and then
//          push the nor of these two elements into the stack
void nor(Dlist<int> &operands) {
    int *num1 = operands.removeBack();
    int *num2 = operands.removeBack();
    int rslt = ~(*num1 | *num2);
    delete num1;
    delete num2;
    auto temp = new int(rslt);
    operands.insertBack(temp);
}

// EFFECTS: pop up the first element in the stack.
//          If this element is zero, pop up the following n instructions in the queue.
//          If this element is not zero, we continue executing the next instruction
void ifz(Dlist<int> &operands, Dlist<Instr> &instructions, int n) {
    auto zero = operands.removeBack();
    if (!*zero) {
        for (int i = 0; i < n; ++i) {
            auto victim = instructions.removeFront();
            delete victim;
        }
    }
    delete zero;
}

// EFFECTS: pop up an element from the stack. This first element is the address.
//          Then, find the value stored at this address and push it into the stack.
void load(Dlist<int> &operands, int memory[]) {
    int *addr = operands.removeBack();
    auto value = new int(memory[*addr]);
    operands.insertBack(value);
    delete addr;
}

// EFFECTS: pop up two elements. The first element is address and the second is value
void store(Dlist<int> &operands, int memory[]) {
    int *addr = operands.removeBack();
    int *value = operands.removeBack();
    memory[*addr] = *value;
    delete addr;
    delete value;
}

// EFFECTS: pop up an element from the operand stack
void pop(Dlist<int> &operands) {
    auto victim = operands.removeBack();
    delete victim;
}

// EFFECTS: push an element into the operand stack
void pushi(Dlist<int> &operands, int n) {
    auto temp = new int(n);
    operands.insertBack(temp);
}

// EFFECTS: pop up an element from the instruction queue
void pop(Dlist<Instr> &instructions) {
    auto victim = instructions.removeBack();
    delete victim;
}

// EFFECTS: free all the op* remain in stack and queue
void freeAll(Dlist<int> &operands, Dlist<Instr> &instructions) {
    while (!operands.isEmpty()) {
        pop(operands);
    }
    while (!instructions.isEmpty()) {
        pop(instructions);
    }
}

int main(int argc, char *argv[]) {
    int memory[16];
    Dlist<int> operands;
    Dlist<Instr> instructions;
    int num_op, num_inst;
    cin >> num_op >> num_inst;
    stack_init(operands, num_op); // stack initialization
    queue_init(instructions, num_inst); // queue initialization
    mem_init(memory); // memory initialization
    bool Halt = false;
    while (!Halt && !instructions.isEmpty()) {
        Instr *curr_instr = instructions.removeFront();
        switch (int(curr_instr->name)) {
            case 0: // ADD
                add(operands);
                break;
            case 1: //NOR
                nor(operands);
                break;
            case 2: // IFZ
                ifz(operands, instructions, curr_instr->parameter);
                break;
            case 3: // HALT
                Halt = true;
                break;
            case 4: // LOAD
                load(operands, memory);
                break;
            case 5: // STORE
                store(operands, memory);
                break;
            case 6: // POP
                pop(operands);
                break;
            case 7: // PUSHI
                pushi(operands, curr_instr->parameter);
                break;
            default: //NOOP
                break;
        }
        if (argc == 1) {
            cout << *curr_instr << '\n' << operands << endl << instructions << endl;
            for (int m : memory) {
                cout << m << ' ';
            }
        }
        delete curr_instr;
    }
    if (argc == 2) {
        cout << operands << endl;
        for (int m : memory) {
            cout << m << ' ';
        }
    }
    cout << endl;
    freeAll(operands, instructions);
    return 0;
}
