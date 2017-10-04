	de2i_150_pcie u0 (
		.altpll_sdram_clk                           (<connected-to-altpll_sdram_clk>),                           //               altpll_sdram.clk
		.clk_clk                                    (<connected-to-clk_clk>),                                    //                        clk.clk
		.pcie_ip_clocks_sim_clk250_export           (<connected-to-pcie_ip_clocks_sim_clk250_export>),           //         pcie_ip_clocks_sim.clk250_export
		.pcie_ip_clocks_sim_clk500_export           (<connected-to-pcie_ip_clocks_sim_clk500_export>),           //                           .clk500_export
		.pcie_ip_clocks_sim_clk125_export           (<connected-to-pcie_ip_clocks_sim_clk125_export>),           //                           .clk125_export
		.pcie_ip_pcie_rstn_export                   (<connected-to-pcie_ip_pcie_rstn_export>),                   //          pcie_ip_pcie_rstn.export
		.pcie_ip_pipe_ext_pipe_mode                 (<connected-to-pcie_ip_pipe_ext_pipe_mode>),                 //           pcie_ip_pipe_ext.pipe_mode
		.pcie_ip_pipe_ext_phystatus_ext             (<connected-to-pcie_ip_pipe_ext_phystatus_ext>),             //                           .phystatus_ext
		.pcie_ip_pipe_ext_rate_ext                  (<connected-to-pcie_ip_pipe_ext_rate_ext>),                  //                           .rate_ext
		.pcie_ip_pipe_ext_powerdown_ext             (<connected-to-pcie_ip_pipe_ext_powerdown_ext>),             //                           .powerdown_ext
		.pcie_ip_pipe_ext_txdetectrx_ext            (<connected-to-pcie_ip_pipe_ext_txdetectrx_ext>),            //                           .txdetectrx_ext
		.pcie_ip_pipe_ext_rxelecidle0_ext           (<connected-to-pcie_ip_pipe_ext_rxelecidle0_ext>),           //                           .rxelecidle0_ext
		.pcie_ip_pipe_ext_rxdata0_ext               (<connected-to-pcie_ip_pipe_ext_rxdata0_ext>),               //                           .rxdata0_ext
		.pcie_ip_pipe_ext_rxstatus0_ext             (<connected-to-pcie_ip_pipe_ext_rxstatus0_ext>),             //                           .rxstatus0_ext
		.pcie_ip_pipe_ext_rxvalid0_ext              (<connected-to-pcie_ip_pipe_ext_rxvalid0_ext>),              //                           .rxvalid0_ext
		.pcie_ip_pipe_ext_rxdatak0_ext              (<connected-to-pcie_ip_pipe_ext_rxdatak0_ext>),              //                           .rxdatak0_ext
		.pcie_ip_pipe_ext_txdata0_ext               (<connected-to-pcie_ip_pipe_ext_txdata0_ext>),               //                           .txdata0_ext
		.pcie_ip_pipe_ext_txdatak0_ext              (<connected-to-pcie_ip_pipe_ext_txdatak0_ext>),              //                           .txdatak0_ext
		.pcie_ip_pipe_ext_rxpolarity0_ext           (<connected-to-pcie_ip_pipe_ext_rxpolarity0_ext>),           //                           .rxpolarity0_ext
		.pcie_ip_pipe_ext_txcompl0_ext              (<connected-to-pcie_ip_pipe_ext_txcompl0_ext>),              //                           .txcompl0_ext
		.pcie_ip_pipe_ext_txelecidle0_ext           (<connected-to-pcie_ip_pipe_ext_txelecidle0_ext>),           //                           .txelecidle0_ext
		.pcie_ip_powerdown_pll_powerdown            (<connected-to-pcie_ip_powerdown_pll_powerdown>),            //          pcie_ip_powerdown.pll_powerdown
		.pcie_ip_powerdown_gxb_powerdown            (<connected-to-pcie_ip_powerdown_gxb_powerdown>),            //                           .gxb_powerdown
		.pcie_ip_reconfig_busy_busy_altgxb_reconfig (<connected-to-pcie_ip_reconfig_busy_busy_altgxb_reconfig>), //      pcie_ip_reconfig_busy.busy_altgxb_reconfig
		.pcie_ip_reconfig_fromgxb_0_data            (<connected-to-pcie_ip_reconfig_fromgxb_0_data>),            // pcie_ip_reconfig_fromgxb_0.data
		.pcie_ip_reconfig_togxb_data                (<connected-to-pcie_ip_reconfig_togxb_data>),                //     pcie_ip_reconfig_togxb.data
		.pcie_ip_refclk_export                      (<connected-to-pcie_ip_refclk_export>),                      //             pcie_ip_refclk.export
		.pcie_ip_rx_in_rx_datain_0                  (<connected-to-pcie_ip_rx_in_rx_datain_0>),                  //              pcie_ip_rx_in.rx_datain_0
		.pcie_ip_test_in_test_in                    (<connected-to-pcie_ip_test_in_test_in>),                    //            pcie_ip_test_in.test_in
		.pcie_ip_tx_out_tx_dataout_0                (<connected-to-pcie_ip_tx_out_tx_dataout_0>),                //             pcie_ip_tx_out.tx_dataout_0
		.reset_reset_n                              (<connected-to-reset_reset_n>)                               //                      reset.reset_n
	);

