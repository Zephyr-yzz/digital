#include "Vmux2_41.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <nvboard.h>
#include <SDL.h>

static TOP_NAME dut;
void nvboard_bind_all_pins(Vmux2_41* top);

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vmux2_41* top;

void step_and_dump_wave(){
  dut.eval();
  nvboard_update();

  top->eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());
}
void sim_init(){
  contextp = new VerilatedContext;
  tfp = new VerilatedVcdC;
  top = new Vmux2_41;
  contextp->traceEverOn(true);
  top->trace(tfp, 0);
  tfp->open("dump.vcd");
}

void sim_exit(){
  step_and_dump_wave();
  tfp->close();
}
int main() {
  nvboard_bind_all_pins(&dut);
  nvboard_init();

  sim_init();
  top->y=0b00;  top->x0=0b1110;  step_and_dump_wave();
                top->x0=0b0001;  step_and_dump_wave();
  top->y=0b01;  top->x1=0b1110;  step_and_dump_wave();
                top->x1=0b0010;  step_and_dump_wave();
  top->y=0b10;  top->x2=0b1010;  step_and_dump_wave();
                top->x2=0b0100;  step_and_dump_wave();
  top->y=0b11;  top->x3=0b0111;  step_and_dump_wave();
                top->x3=0b1001;  step_and_dump_wave();
  sim_exit();
}
