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

-- DATE "01/12/2022 08:57:05"

-- 
-- Device: Altera EP2S15F484C3 Package FBGA484
-- 

-- 
-- This VHDL file should be used for Custom VHDL only
-- 

LIBRARY IEEE, stratixii;
USE IEEE.std_logic_1164.all;
USE stratixii.stratixii_components.all;

ENTITY 	\ex2-3\ IS
    PORT (
	Q1 : OUT std_logic;
	\in\ : IN std_logic;
	CLK : IN std_logic;
	Q2 : OUT std_logic;
	Q3 : OUT std_logic
	);
END \ex2-3\;

ARCHITECTURE structure OF \ex2-3\ IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_Q1 : std_logic;
SIGNAL \ww_in\ : std_logic;
SIGNAL ww_CLK : std_logic;
SIGNAL ww_Q2 : std_logic;
SIGNAL ww_Q3 : std_logic;
SIGNAL \CLK~clkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \CLK~combout\ : std_logic;
SIGNAL \CLK~clkctrl_outclk\ : std_logic;
SIGNAL \in~combout\ : std_logic;
SIGNAL \inst~14_combout\ : std_logic;
SIGNAL \inst~regout\ : std_logic;
SIGNAL \inst3~10_combout\ : std_logic;
SIGNAL \inst3~regout\ : std_logic;
SIGNAL \inst4~20_combout\ : std_logic;
SIGNAL \inst4~regout\ : std_logic;
SIGNAL \inst~14DUPLICATE_combout\ : std_logic;
SIGNAL \inst~DUPLICATE_regout\ : std_logic;
SIGNAL \ALT_INV_inst~regout\ : std_logic;
SIGNAL \ALT_INV_inst3~regout\ : std_logic;
SIGNAL \ALT_INV_inst4~regout\ : std_logic;
SIGNAL \ALT_INV_in~combout\ : std_logic;
SIGNAL \ALT_INV_CLK~clkctrl_outclk\ : std_logic;
SIGNAL \ALT_INV_inst~DUPLICATE_regout\ : std_logic;

BEGIN

Q1 <= ww_Q1;
\ww_in\ <= \in\;
ww_CLK <= CLK;
Q2 <= ww_Q2;
Q3 <= ww_Q3;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

\CLK~clkctrl_INCLK_bus\ <= (gnd & gnd & gnd & \CLK~combout\);
\ALT_INV_inst~regout\ <= NOT \inst~regout\;
\ALT_INV_inst3~regout\ <= NOT \inst3~regout\;
\ALT_INV_inst4~regout\ <= NOT \inst4~regout\;
\ALT_INV_in~combout\ <= NOT \in~combout\;
\ALT_INV_CLK~clkctrl_outclk\ <= NOT \CLK~clkctrl_outclk\;
\ALT_INV_inst~DUPLICATE_regout\ <= NOT \inst~DUPLICATE_regout\;

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

\CLK~clkctrl\ : stratixii_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock")
-- pragma translate_on
PORT MAP (
	inclk => \CLK~clkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \CLK~clkctrl_outclk\);

\in~I\ : stratixii_io
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
	padio => \ww_in\,
	combout => \in~combout\);

\inst~14\ : stratixii_lcell_comb
-- Equation(s):
-- \inst~14_combout\ = \inst~regout\ & \inst4~regout\ & ( !\in~combout\ ) # \inst~regout\ & !\inst4~regout\ & ( !\in~combout\ ) # !\inst~regout\ & !\inst4~regout\

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "1111111111111111111100001111000000000000000000001111000011110000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => \ALT_INV_in~combout\,
	datae => \ALT_INV_inst~regout\,
	dataf => \ALT_INV_inst4~regout\,
	combout => \inst~14_combout\);

inst : stratixii_lcell_ff
PORT MAP (
	clk => \ALT_INV_CLK~clkctrl_outclk\,
	datain => \inst~14_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst~regout\);

\inst3~10\ : stratixii_lcell_comb
-- Equation(s):
-- \inst3~10_combout\ = !\inst3~regout\ & \inst~regout\ # \inst3~regout\ & !\inst~regout\

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000111111111111111111111111111111110000000000000000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datae => \ALT_INV_inst3~regout\,
	dataf => \ALT_INV_inst~regout\,
	combout => \inst3~10_combout\);

inst3 : stratixii_lcell_ff
PORT MAP (
	clk => \ALT_INV_CLK~clkctrl_outclk\,
	datain => \inst3~10_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst3~regout\);

\inst4~20\ : stratixii_lcell_comb
-- Equation(s):
-- \inst4~20_combout\ = \inst4~regout\ & \inst3~regout\ & ( !\in~combout\ ) # !\inst4~regout\ & \inst3~regout\ & ( \inst~DUPLICATE_regout\ ) # \inst4~regout\ & !\inst3~regout\ & ( !\in~combout\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000101010101010101000000000111111111010101010101010",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_in~combout\,
	datad => \ALT_INV_inst~DUPLICATE_regout\,
	datae => \ALT_INV_inst4~regout\,
	dataf => \ALT_INV_inst3~regout\,
	combout => \inst4~20_combout\);

inst4 : stratixii_lcell_ff
PORT MAP (
	clk => \ALT_INV_CLK~clkctrl_outclk\,
	datain => \inst4~20_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst4~regout\);

\inst~14DUPLICATE\ : stratixii_lcell_comb
-- Equation(s):
-- \inst~14DUPLICATE_combout\ = \inst~DUPLICATE_regout\ & \inst4~regout\ & ( !\in~combout\ ) # \inst~DUPLICATE_regout\ & !\inst4~regout\ & ( !\in~combout\ ) # !\inst~DUPLICATE_regout\ & !\inst4~regout\

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "1111111111111111111111110000000000000000000000001111111100000000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datad => \ALT_INV_in~combout\,
	datae => \ALT_INV_inst~DUPLICATE_regout\,
	dataf => \ALT_INV_inst4~regout\,
	combout => \inst~14DUPLICATE_combout\);

\inst~DUPLICATE\ : stratixii_lcell_ff
PORT MAP (
	clk => \ALT_INV_CLK~clkctrl_outclk\,
	datain => \inst~14DUPLICATE_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst~DUPLICATE_regout\);

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
	datain => \inst~DUPLICATE_regout\,
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
	datain => \inst3~regout\,
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
	datain => \inst4~regout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_Q3);
END structure;


