
module de2i_150_pcie (
	altpll_sdram_clk,
	clk_clk,
	pcie_ip_clocks_sim_clk250_export,
	pcie_ip_clocks_sim_clk500_export,
	pcie_ip_clocks_sim_clk125_export,
	pcie_ip_pcie_rstn_export,
	pcie_ip_pipe_ext_pipe_mode,
	pcie_ip_pipe_ext_phystatus_ext,
	pcie_ip_pipe_ext_rate_ext,
	pcie_ip_pipe_ext_powerdown_ext,
	pcie_ip_pipe_ext_txdetectrx_ext,
	pcie_ip_pipe_ext_rxelecidle0_ext,
	pcie_ip_pipe_ext_rxdata0_ext,
	pcie_ip_pipe_ext_rxstatus0_ext,
	pcie_ip_pipe_ext_rxvalid0_ext,
	pcie_ip_pipe_ext_rxdatak0_ext,
	pcie_ip_pipe_ext_txdata0_ext,
	pcie_ip_pipe_ext_txdatak0_ext,
	pcie_ip_pipe_ext_rxpolarity0_ext,
	pcie_ip_pipe_ext_txcompl0_ext,
	pcie_ip_pipe_ext_txelecidle0_ext,
	pcie_ip_powerdown_pll_powerdown,
	pcie_ip_powerdown_gxb_powerdown,
	pcie_ip_reconfig_busy_busy_altgxb_reconfig,
	pcie_ip_reconfig_fromgxb_0_data,
	pcie_ip_reconfig_togxb_data,
	pcie_ip_refclk_export,
	pcie_ip_rx_in_rx_datain_0,
	pcie_ip_test_in_test_in,
	pcie_ip_tx_out_tx_dataout_0,
	reset_reset_n);	

	output		altpll_sdram_clk;
	input		clk_clk;
	output		pcie_ip_clocks_sim_clk250_export;
	output		pcie_ip_clocks_sim_clk500_export;
	output		pcie_ip_clocks_sim_clk125_export;
	input		pcie_ip_pcie_rstn_export;
	input		pcie_ip_pipe_ext_pipe_mode;
	input		pcie_ip_pipe_ext_phystatus_ext;
	output		pcie_ip_pipe_ext_rate_ext;
	output	[1:0]	pcie_ip_pipe_ext_powerdown_ext;
	output		pcie_ip_pipe_ext_txdetectrx_ext;
	input		pcie_ip_pipe_ext_rxelecidle0_ext;
	input	[7:0]	pcie_ip_pipe_ext_rxdata0_ext;
	input	[2:0]	pcie_ip_pipe_ext_rxstatus0_ext;
	input		pcie_ip_pipe_ext_rxvalid0_ext;
	input		pcie_ip_pipe_ext_rxdatak0_ext;
	output	[7:0]	pcie_ip_pipe_ext_txdata0_ext;
	output		pcie_ip_pipe_ext_txdatak0_ext;
	output		pcie_ip_pipe_ext_rxpolarity0_ext;
	output		pcie_ip_pipe_ext_txcompl0_ext;
	output		pcie_ip_pipe_ext_txelecidle0_ext;
	input		pcie_ip_powerdown_pll_powerdown;
	input		pcie_ip_powerdown_gxb_powerdown;
	input		pcie_ip_reconfig_busy_busy_altgxb_reconfig;
	output	[4:0]	pcie_ip_reconfig_fromgxb_0_data;
	input	[3:0]	pcie_ip_reconfig_togxb_data;
	input		pcie_ip_refclk_export;
	input		pcie_ip_rx_in_rx_datain_0;
	input	[39:0]	pcie_ip_test_in_test_in;
	output		pcie_ip_tx_out_tx_dataout_0;
	input		reset_reset_n;
endmodule
