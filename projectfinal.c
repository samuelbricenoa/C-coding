#include "spimcore.h"

/* ALU */
/* 10 Points */
void ALU(unsigned A,unsigned B,char ALUControl,unsigned *ALUresult,char *Zero)
{
    //ALU Control 000
    if (ALUControl == 0){
        //Z = A + B
        *ALUresult = A + B;
    }
    //ALU Control 001
    if (ALUControl == 1) {
        //Z = A - B
        *ALUresult = A - B;
    }
    //ALU Control 010
    if (ALUControl == 2) {
         if ((int) A < (int) B) {
               *ALUresult = 1;
           }
           else{
               *ALUresult = 0;
           }
    }
    //ALU Control 011
    if (ALUControl == 3) {
        //if A < B, Z = 1; otherwise, Z = 0 (A and B are unsigned integers)
        if (A < B) {
            *ALUresult = 1;
            *Zero = 0;
        }
        else{
            *ALUresult = 0;
            *Zero = 1;
        }
    }
    //ALU Control 100
    if (ALUControl == 4) {
        //Z = A AND B
        *ALUresult = A & B;
    }
    //ALU Control 101
    if (ALUControl == 5) {
        //Z = A OR B
        *ALUresult = A | B;
    }
    //ALU Control 110
    if (ALUControl == 6) {
        //Shift left B by 16 bits
        B = B << 16;
    }
    //ALU Control 111
    if (ALUControl == 7) {
        //Z = NOT A
        *ALUresult = ~A ;
    }
}

/* instruction fetch */
/* 10 Points */
int instruction_fetch(unsigned PC,unsigned *Mem,unsigned *instruction)
{
    //Fetch the instruction addressed by PC from Mem and write it to instruction.
    if (PC > 65536 && PC % 4 != 0 && PC < 0){
         return 1;
    }
    else{
        *instruction = Mem[PC >> 2];
        return 0;
    }
}

/* instruction partition */
/* 10 Points */
void instruction_partition(unsigned instruction, unsigned *op, unsigned *r1,unsigned *r2, unsigned *r3, unsigned *funct, unsigned *offset, unsigned *jsec)
{
    // instruction [31-26]
    *op = (instruction >> 26);
    // instruction [25-21]//0001 1111
    *r1 = (instruction >> 21) & (0x1f) ;
    // instruction [20-16]
    *r2 = (instruction >> 16) & (0x1f) ;
    // instruction [15-11]
    *r3 = (instruction >> 11) & (0x1f);
    // instruction [5-0]
    *funct = (instruction) & (0x3f);
    // instruction [15-0]//1111 1111 1111 1111
    *offset = (instruction) & (0xffff);
    // instruction [25-0]
    *jsec = (instruction) & (0x3ffffff) ;
}

/* instruction decode */
/* 15 Points */
int instruction_decode(unsigned op,struct_controls *controls)
{
    int Halt = 1;
    //R_Type
    if(op == 0x0)
    {
        controls->RegDst = 1;
        controls->Jump = 0;
        controls->Branch = 0;
        controls->MemRead = 0;
        controls->MemtoReg = 0;
        controls->ALUOp = 7;
        controls->MemWrite = 0;
        controls->ALUSrc = 0;
        controls->RegWrite = 1;

        Halt = 0;
    }
    //addi
    if(op == 0x8)
    {
        controls->RegDst = 0;
        controls->Jump = 0;
        controls->Branch = 0;
        controls->MemRead = 0;
        controls->MemtoReg = 0;
        controls->ALUOp = 0;
        controls->MemWrite = 0;
        controls->ALUSrc = 1;
        controls->RegWrite = 1;

        Halt = 0;
    }
    //lw
    if(op == 0x23)
    {
        controls->RegDst = 0;
        controls->Jump = 0;
        controls->Branch = 0;
        controls->MemRead = 1;
        controls->MemtoReg = 1;
        controls->ALUOp = 0;
        controls->MemWrite = 0;
        controls->ALUSrc = 1;
        controls->RegWrite = 1;

        Halt = 0;
    }
    //sw
    if(op == 0x2b)
    {
        controls->RegDst = 2;
        controls->Jump = 0;
        controls->Branch = 0;
        controls->MemRead = 0;
        controls->MemtoReg = 2;
        controls->ALUOp = 0;
        controls->MemWrite = 1;
        controls->ALUSrc = 1;
        controls->RegWrite = 0;

        Halt = 0;
    }

    //lui not sure
    if(op == 0xf)
    {
        controls->RegDst = 0;
        controls->Jump = 0;
        controls->Branch = 0;
        controls->MemRead = 1;
        controls->MemtoReg = 1;
        controls->ALUOp = 0;
        controls->MemWrite = 0;
        controls->ALUSrc = 1;
        controls->RegWrite = 1;


        Halt = 0;

    }
    //beq
    if(op == 0x4)
    {
        controls->RegDst = 2;
        controls->Jump = 0;
        controls->Branch = 1;
        controls->MemRead = 0;
        controls->MemtoReg = 2;
        controls->ALUOp = 1;
        controls->MemWrite = 0;
        controls->ALUSrc = 1;
        controls->RegWrite = 0;

        Halt = 0;
    }
    //slti not sure
    if(op == 0xa)
    {
        controls->RegDst = 0;
        controls->Jump = 0;
        controls->Branch = 0;
        controls->MemRead = 0;
        controls->MemtoReg = 0;
        controls->ALUOp = 2;
        controls->MemWrite = 0;
        controls->ALUSrc = 1;
        controls->RegWrite = 1;

        Halt = 0;
    }
    //sltiu not sure
    if(op == 0xb)
    {
        controls->RegDst = 0;
        controls->Jump = 0;
        controls->Branch = 0;
        controls->MemRead = 0;
        controls->MemtoReg = 0;
        controls->ALUOp = 3;
        controls->MemWrite = 0;
        controls->ALUSrc = 1;
        controls->RegWrite = 1;

        Halt = 0;
    }
    //Jump not sure
    if(op == 0x2)
    {
        controls->RegDst = 2;
        controls->Jump = 1;
        controls->Branch = 0;
        controls->MemRead = 0;
        controls->MemtoReg = 0;
        controls->ALUOp = 0;
        controls->MemWrite = 0;
        controls->ALUSrc = 2;
        controls->RegWrite = 0;

        Halt = 0;
    }
    return Halt;

    
}

/* Read Register */
/* 5 Points */
void read_register(unsigned r1,unsigned r2,unsigned *Reg,unsigned *data1,unsigned *data2)
{
    //Read the registers addressed by r1 and r2 from Reg, and write the read values to data1 and data2 respectively.
    *data1 = Reg[r1];
    *data2 = Reg[r2];
}

/* Sign Extend */
/* 10 Points */
void sign_extend(unsigned offset,unsigned *extended_value)
{
    //Assign the sign-extended value of offset to extended_value.
    //16bits = 0xFFFF // offset = 1111 1111 1111 1111
    if (offset & 0x8000){
        *extended_value = offset | 0xffff0000;
    }
    else
    {
        *extended_value = offset & 0xffffffff;
    }
        
}

/* ALU operations /
/ 10 Points */
int ALU_operations(unsigned data1,unsigned data2,unsigned extended_value,unsigned funct,char ALUOp,char ALUSrc,unsigned *ALUresult,char *Zero)
{
    int chosenOne;
    if(ALUSrc == 1)
    {
        chosenOne = extended_value;

    }
    else
    {
        chosenOne = data2;
    }

    if(ALUOp != 7)
    {
         ALU(data1, chosenOne, ALUOp, ALUresult, Zero);
    }
    else
    {
        int tempFunct;
        if(funct == 0x20)
        {
            tempFunct = 0;
        }
        else if (funct == 0x22)
        {
            tempFunct = 1;
        }
        else if (funct == 0x24)
        {
            tempFunct = 4;
        }
        else if (funct == 0x25)
        {
            tempFunct = 5;
        }
        else if (funct == 0x28)
        {
            tempFunct = 2;
        }
        else if (funct == 0x2b)
        {
            tempFunct = 3;
        }
        else
        {
            return 1;
        }

         ALU(data1, chosenOne, tempFunct, ALUresult, Zero);
    }

    return 0;
}

/* Read / Write Memory */
/* 10 Points */
int rw_memory(unsigned ALUresult,unsigned data2,char MemWrite,char MemRead,unsigned *memdata,unsigned *Mem)
{
    //rw_memory() in the event that ((ALUresult % 4)!=0)?
    if ((ALUresult % 4)!= 0 && (MemRead == 1 || MemWrite == 1))
    {
        return 1;
    }
    //If MemWrite = 1, write into memory...
    if (MemWrite ==  1){
        Mem[ALUresult >> 2] = data2;
    }
    //If MemRead = 1, read from memory
    if (MemRead == 1){
        *memdata = Mem[ALUresult >> 2];
    }
    return 0;
}

/* Write Register */
/* 10 Points */
void write_register(unsigned r2,unsigned r3,unsigned memdata,unsigned ALUresult,char RegWrite,char RegDst,char MemtoReg,unsigned *Reg)
{
    // data coming from memory
    if(RegWrite == 1 && MemtoReg == 1)
    {
        if(RegDst == 1)
        {
            Reg[r3] = memdata;

        }
        else
        {
            Reg[r2] = memdata;
        }

    }

    // data coming from ALUresult
    if(RegWrite == 1 && MemtoReg == 0)
    {
        if(RegDst == 1)
        {
            Reg[r3] = ALUresult;

        }
        else
        {
            Reg[r2] = ALUresult;
        }
    }
}

/* PC update */
/* 10 Points */
void PC_update(unsigned jsec,unsigned extended_value,char Branch,char Jump,char Zero,unsigned *PC)
{
    *PC = *PC + 4;
    
    if(Jump == 1){
        *PC = (jsec << 2) | (*PC & 0xF0000000);
    }
    else if (Branch ==  1 && Zero == 1){
        *PC = *PC + extended_value << 2;
    }
}
