# THIS FILE IS AUTOMATICALLY GENERATED
# Project: I:\ControllerKinect\Receiver\Receiver.cydsn\Receiver.cyprj
# Date: Tue, 03 Jan 2012 05:26:58 GMT
#set_units -time ns
create_clock -name {ClockBlock/clk_bus} -period 41.666666666666664 -waveform {0 20.8333333333333} [get_pins {ClockBlock/clk_bus}]
create_clock -name {ClockBlock/dclk_0} -period 250 -waveform {0 125} [get_pins {ClockBlock/dclk_0}]
create_clock -name {CyIMO} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyMASTER_CLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/clk_sync}] -divide_by 6 -duty_cycle 50 [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -duty_cycle 50 [list [get_pins {ClockBlock/clk_bus_glb}]]


# Component constraints for I:\ControllerKinect\Receiver\Receiver.cydsn\TopDesign\TopDesign.cysch
# Project: I:\ControllerKinect\Receiver\Receiver.cydsn\Receiver.cyprj
# Date: Tue, 03 Jan 2012 05:26:51 GMT
