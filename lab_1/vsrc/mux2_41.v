module mux2_41(
    input [3:0] x0,
    input [3:0] x1,
    input [3:0] x2,
    input [3:0] x3,
    input [1:0] y,
    output reg [3:0] f
);
    assign f = (y == 2'b00) ? x0 :
               (y == 2'b01) ? x1 :
               (y == 2'b10) ? x2 :
                              x3 ;
endmodule //mux2_41
