-- Copyright (C) 1991-2008 Altera Corporation
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, Altera MegaCore Function License 
-- Agreement, or other applicable license agreement, including, 
-- without limitation, that your use is for the sole purpose of 
-- programming logic devices manufactured by Altera and sold by 
-- Altera or its authorized distributors.  Please refer to the 
-- applicable agreement for further details.

-- VENDOR "Altera"
-- PROGRAM "Quartus II"
-- VERSION "Version 8.1 Build 163 10/28/2008 SJ Web Edition"

-- DATE "01/12/2022 10:09:21"

-- 
-- Device: Altera EP2S15F484C3 Package FBGA484
-- 

-- 
-- This VHDL file should be used for Custom VHDL only
-- 

LIBRARY IEEE, stratixii;
USE IEEE.std_logic_1164.all;
USE stratixii.stratixii_components.all;

ENTITY 	\ex2-1-remake\ IS
    PORT (
	Q1 : OUT std_logic;
	K : IN std_logic;
	J : IN std_logic;
	CLK : IN std_logic;
	Q2 : OUT std_logic;
	Q3 : OUT std_logic
	);
END \ex2-1-remake\;

ARCHITECTURE structure OF \ex2-1-remake\ IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_Q1 : std_logic;
SIGNAL ww_K : std_logic;
SIGNAL ww_J : std_logic;
SIGNAL ww_CLK : std_logic;
SIGNAL ww_Q2 : std_logic;
SIGNAL ww_Q3 : std_logic;
SIGNAL \inst1~clkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \CLK~combout\ : std_logic;
SIGNAL \K~combout\ : std_logic;
SIGNAL \J~combout\ : std_logic;
SIGNAL \inst~13_combout\ : std_logic;
SIGNAL \inst7~13_combout\ : std_logic;
SIGNAL \inst7~regout\ : std_logic;
SIGNAL \inst1~combout\ : std_logic;
SIGNAL \inst1~clkctrl_outclk\ : std_logic;
SIGNAL \inst~regout\ : std_logic;
SIGNAL \inst4~13_combout\ : std_logic;
SIGNAL \inst4~regout\ : std_logic;
SIGNAL \ALT_INV_inst~regout\ : std_logic;
SIGNAL \ALT_INV_inst4~regout\ : std_logic;
SIGNAL \ALT_INV_inst7~regout\ : std_logic;
SIGNAL \ALT_INV_K~combout\ : std_logic;
SIGNAL \ALT_INV_J~combout\ : std_logic;
SIGNAL \ALT_INV_CLK~combout\ : std_logic;

BEGIN

Q1 <= ww_Q1;
ww_K <= K;
ww_J <= J;
ww_CLK <= CLK;
Q2 <= ww_Q2;
Q3 <= ww_Q3;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

\inst1~clkctrl_INCLK_bus\ <= (gnd & gnd & gnd & \inst1~combout\);
\ALT_INV_inst~regout\ <= NOT \inst~regout\;
\ALT_INV_inst4~regout\ <= NOT \inst4~regout\;
\ALT_INV_inst7~regout\ <= NOT \inst7~regout\;
\ALT_INV_K~combout\ <= NOT \K~combout\;
\ALT_INV_J~combout\ <= NOT \J~combout\;
\ALT_INV_CLK~combout\ <= NOT \CLK~combout\;

\CLK~I\ : stratixii_io
-- pragma translate_off
GENERIC MAP (
	ddio_mode => "none",
	ddioinclk_input => "negated_inclk",
	dqs_delay_buffer_mode => "none",
	dqs_out_mode => "none",
	inclk_input => "normal",
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none",
	sim_dqs_delay_increment => 0,
	sim_dqs_intrinsic_delay => 0,
	sim_dqs_offset_increment => 0)
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_CLK,
	combout => \CLK~combout\);

\K~I\ : stratixii_io
-- pragma translate_off
GENERIC MAP (
	ddio_mode => "none",
	ddioinclk_input => "negated_inclk",
	dqs_delay_buffer_mode => "none",
	dqs_out_mode => "none",
	inclk_input => "normal",
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none",
	sim_dqs_delay_increment => 0,
	sim_dqs_intrinsic_delay => 0,
	sim_dqs_offset_increment => 0)
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_K,
	combout => \K~combout\);

\J~I\ : stratixii_io
-- pragma translate_off
GENERIC MAP (
	ddio_mode => "none",
	ddioinclk_input => "negated_inclk",
	dqs_delay_buffer_mode => "none",
	dqs_out_mode => "none",
	inclk_input => "normal",
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none",
	sim_dqs_delay_increment => 0,
	sim_dqs_intrinsic_delay => 0,
	sim_dqs_offset_increment => 0)
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_J,
	combout => \J~combout\);

\inst~13\ : stratixii_lcell_comb
-- Equation(s):
-- \inst~13_combout\ = \inst~regout\ & \J~combout\ & ( !\K~combout\ ) # !\inst~regout\ & \J~combout\ # \inst~regout\ & !\J~combout\ & ( !\K~combout\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000110011001100110011111111111111111100110011001100",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_K~combout\,
	datae => \ALT_INV_inst~regout\,
	dataf => \ALT_INV_J~combout\,
	combout => \inst~13_combout\);

\inst7~13\ : stratixii_lcell_comb
-- Equation(s):
-- \inst7~13_combout\ = \inst7~regout\ & ( !\K~combout\ ) # !\inst7~regout\ & ( \J~combout\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0101010101010101111100001111000001010101010101011111000011110000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_J~combout\,
	datac => \ALT_INV_K~combout\,
	datae => \ALT_INV_inst7~regout\,
	combout => \inst7~13_combout\);

inst7 : stratixii_lcell_ff
PORT MAP (
	clk => \ALT_INV_inst4~regout\,
	datain => \inst7~13_combout\,
	aclr => \inst1~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst7~regout\);

inst1 : stratixii_lcell_comb
-- Equation(s):
-- \inst1~combout\ = \inst7~regout\ & ( \inst~regout\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000001111000011110000111100001111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => \ALT_INV_inst~regout\,
	dataf => \ALT_INV_inst7~regout\,
	combout => \inst1~combout\);

\inst1~clkctrl\ : stratixii_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock")
-- pragma translate_on
PORT MAP (
	inclk => \inst1~clkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \inst1~clkctrl_outclk\);

inst : stratixii_lcell_ff
PORT MAP (
	clk => \ALT_INV_CLK~combout\,
	datain => \inst~13_combout\,
	aclr => \inst1~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst~regout\);

\inst4~13\ : stratixii_lcell_comb
-- Equation(s):
-- \inst4~13_combout\ = \J~combout\ & ( !\K~combout\ # !\inst4~regout\ ) # !\J~combout\ & ( !\K~combout\ & \inst4~regout\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000011001100000000001100110011111111110011001111111111001100",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_K~combout\,
	datad => \ALT_INV_inst4~regout\,
	dataf => \ALT_INV_J~combout\,
	combout => \inst4~13_combout\);

inst4 : stratixii_lcell_ff
PORT MAP (
	clk => \ALT_INV_inst~regout\,
	datain => \inst4~13_combout\,
	aclr => \inst1~clkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst4~regout\);

\Q1~I\ : stratixii_io
-- pragma translate_off
GENERIC MAP (
	ddio_mode => "none",
	ddioinclk_input => "negated_inclk",
	dqs_delay_buffer_mode => "none",
	dqs_out_mode => "none",
	inclk_input => "normal",
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "output",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none",
	sim_dqs_delay_increment => 0,
	sim_dqs_intrinsic_delay => 0,
	sim_dqs_offset_increment => 0)
-- pragma translate_on
PORT MAP (
	datain => \inst~regout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_Q1);

\Q2~I\ : stratixii_io
-- pragma translate_off
GENERIC MAP (
	ddio_mode => "none",
	ddioinclk_input => "negated_inclk",
	dqs_delay_buffer_mode => "none",
	dqs_out_mode => "none",
	inclk_input => "normal",
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "output",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none",
	sim_dqs_delay_increment => 0,
	sim_dqs_intrinsic_delay => 0,
	sim_dqs_offset_increment => 0)
-- pragma translate_on
PORT MAP (
	datain => \inst4~regout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_Q2);

\Q3~I\ : stratixii_io
-- pragma translate_off
GENERIC MAP (
	ddio_mode => "none",
	ddioinclk_input => "negated_inclk",
	dqs_delay_buffer_mode => "none",
	dqs_out_mode => "none",
	inclk_input => "normal",
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "output",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none",
	sim_dqs_delay_increment => 0,
	sim_dqs_intrinsic_delay => 0,
	sim_dqs_offset_increment => 0)
-- pragma translate_on
PORT MAP (
	datain => \inst7~regout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_Q3);
END structure;


