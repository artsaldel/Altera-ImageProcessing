	component de2i_150_pcie is
		port (
			altpll_sdram_clk                           : out std_logic;                                        -- clk
			clk_clk                                    : in  std_logic                     := 'X';             -- clk
			pcie_ip_clocks_sim_clk250_export           : out std_logic;                                        -- clk250_export
			pcie_ip_clocks_sim_clk500_export           : out std_logic;                                        -- clk500_export
			pcie_ip_clocks_sim_clk125_export           : out std_logic;                                        -- clk125_export
			pcie_ip_pcie_rstn_export                   : in  std_logic                     := 'X';             -- export
			pcie_ip_pipe_ext_pipe_mode                 : in  std_logic                     := 'X';             -- pipe_mode
			pcie_ip_pipe_ext_phystatus_ext             : in  std_logic                     := 'X';             -- phystatus_ext
			pcie_ip_pipe_ext_rate_ext                  : out std_logic;                                        -- rate_ext
			pcie_ip_pipe_ext_powerdown_ext             : out std_logic_vector(1 downto 0);                     -- powerdown_ext
			pcie_ip_pipe_ext_txdetectrx_ext            : out std_logic;                                        -- txdetectrx_ext
			pcie_ip_pipe_ext_rxelecidle0_ext           : in  std_logic                     := 'X';             -- rxelecidle0_ext
			pcie_ip_pipe_ext_rxdata0_ext               : in  std_logic_vector(7 downto 0)  := (others => 'X'); -- rxdata0_ext
			pcie_ip_pipe_ext_rxstatus0_ext             : in  std_logic_vector(2 downto 0)  := (others => 'X'); -- rxstatus0_ext
			pcie_ip_pipe_ext_rxvalid0_ext              : in  std_logic                     := 'X';             -- rxvalid0_ext
			pcie_ip_pipe_ext_rxdatak0_ext              : in  std_logic                     := 'X';             -- rxdatak0_ext
			pcie_ip_pipe_ext_txdata0_ext               : out std_logic_vector(7 downto 0);                     -- txdata0_ext
			pcie_ip_pipe_ext_txdatak0_ext              : out std_logic;                                        -- txdatak0_ext
			pcie_ip_pipe_ext_rxpolarity0_ext           : out std_logic;                                        -- rxpolarity0_ext
			pcie_ip_pipe_ext_txcompl0_ext              : out std_logic;                                        -- txcompl0_ext
			pcie_ip_pipe_ext_txelecidle0_ext           : out std_logic;                                        -- txelecidle0_ext
			pcie_ip_powerdown_pll_powerdown            : in  std_logic                     := 'X';             -- pll_powerdown
			pcie_ip_powerdown_gxb_powerdown            : in  std_logic                     := 'X';             -- gxb_powerdown
			pcie_ip_reconfig_busy_busy_altgxb_reconfig : in  std_logic                     := 'X';             -- busy_altgxb_reconfig
			pcie_ip_reconfig_fromgxb_0_data            : out std_logic_vector(4 downto 0);                     -- data
			pcie_ip_reconfig_togxb_data                : in  std_logic_vector(3 downto 0)  := (others => 'X'); -- data
			pcie_ip_refclk_export                      : in  std_logic                     := 'X';             -- export
			pcie_ip_rx_in_rx_datain_0                  : in  std_logic                     := 'X';             -- rx_datain_0
			pcie_ip_test_in_test_in                    : in  std_logic_vector(39 downto 0) := (others => 'X'); -- test_in
			pcie_ip_tx_out_tx_dataout_0                : out std_logic;                                        -- tx_dataout_0
			reset_reset_n                              : in  std_logic                     := 'X'              -- reset_n
		);
	end component de2i_150_pcie;

	u0 : component de2i_150_pcie
		port map (
			altpll_sdram_clk                           => CONNECTED_TO_altpll_sdram_clk,                           --               altpll_sdram.clk
			clk_clk                                    => CONNECTED_TO_clk_clk,                                    --                        clk.clk
			pcie_ip_clocks_sim_clk250_export           => CONNECTED_TO_pcie_ip_clocks_sim_clk250_export,           --         pcie_ip_clocks_sim.clk250_export
			pcie_ip_clocks_sim_clk500_export           => CONNECTED_TO_pcie_ip_clocks_sim_clk500_export,           --                           .clk500_export
			pcie_ip_clocks_sim_clk125_export           => CONNECTED_TO_pcie_ip_clocks_sim_clk125_export,           --                           .clk125_export
			pcie_ip_pcie_rstn_export                   => CONNECTED_TO_pcie_ip_pcie_rstn_export,                   --          pcie_ip_pcie_rstn.export
			pcie_ip_pipe_ext_pipe_mode                 => CONNECTED_TO_pcie_ip_pipe_ext_pipe_mode,                 --           pcie_ip_pipe_ext.pipe_mode
			pcie_ip_pipe_ext_phystatus_ext             => CONNECTED_TO_pcie_ip_pipe_ext_phystatus_ext,             --                           .phystatus_ext
			pcie_ip_pipe_ext_rate_ext                  => CONNECTED_TO_pcie_ip_pipe_ext_rate_ext,                  --                           .rate_ext
			pcie_ip_pipe_ext_powerdown_ext             => CONNECTED_TO_pcie_ip_pipe_ext_powerdown_ext,             --                           .powerdown_ext
			pcie_ip_pipe_ext_txdetectrx_ext            => CONNECTED_TO_pcie_ip_pipe_ext_txdetectrx_ext,            --                           .txdetectrx_ext
			pcie_ip_pipe_ext_rxelecidle0_ext           => CONNECTED_TO_pcie_ip_pipe_ext_rxelecidle0_ext,           --                           .rxelecidle0_ext
			pcie_ip_pipe_ext_rxdata0_ext               => CONNECTED_TO_pcie_ip_pipe_ext_rxdata0_ext,               --                           .rxdata0_ext
			pcie_ip_pipe_ext_rxstatus0_ext             => CONNECTED_TO_pcie_ip_pipe_ext_rxstatus0_ext,             --                           .rxstatus0_ext
			pcie_ip_pipe_ext_rxvalid0_ext              => CONNECTED_TO_pcie_ip_pipe_ext_rxvalid0_ext,              --                           .rxvalid0_ext
			pcie_ip_pipe_ext_rxdatak0_ext              => CONNECTED_TO_pcie_ip_pipe_ext_rxdatak0_ext,              --                           .rxdatak0_ext
			pcie_ip_pipe_ext_txdata0_ext               => CONNECTED_TO_pcie_ip_pipe_ext_txdata0_ext,               --                           .txdata0_ext
			pcie_ip_pipe_ext_txdatak0_ext              => CONNECTED_TO_pcie_ip_pipe_ext_txdatak0_ext,              --                           .txdatak0_ext
			pcie_ip_pipe_ext_rxpolarity0_ext           => CONNECTED_TO_pcie_ip_pipe_ext_rxpolarity0_ext,           --                           .rxpolarity0_ext
			pcie_ip_pipe_ext_txcompl0_ext              => CONNECTED_TO_pcie_ip_pipe_ext_txcompl0_ext,              --                           .txcompl0_ext
			pcie_ip_pipe_ext_txelecidle0_ext           => CONNECTED_TO_pcie_ip_pipe_ext_txelecidle0_ext,           --                           .txelecidle0_ext
			pcie_ip_powerdown_pll_powerdown            => CONNECTED_TO_pcie_ip_powerdown_pll_powerdown,            --          pcie_ip_powerdown.pll_powerdown
			pcie_ip_powerdown_gxb_powerdown            => CONNECTED_TO_pcie_ip_powerdown_gxb_powerdown,            --                           .gxb_powerdown
			pcie_ip_reconfig_busy_busy_altgxb_reconfig => CONNECTED_TO_pcie_ip_reconfig_busy_busy_altgxb_reconfig, --      pcie_ip_reconfig_busy.busy_altgxb_reconfig
			pcie_ip_reconfig_fromgxb_0_data            => CONNECTED_TO_pcie_ip_reconfig_fromgxb_0_data,            -- pcie_ip_reconfig_fromgxb_0.data
			pcie_ip_reconfig_togxb_data                => CONNECTED_TO_pcie_ip_reconfig_togxb_data,                --     pcie_ip_reconfig_togxb.data
			pcie_ip_refclk_export                      => CONNECTED_TO_pcie_ip_refclk_export,                      --             pcie_ip_refclk.export
			pcie_ip_rx_in_rx_datain_0                  => CONNECTED_TO_pcie_ip_rx_in_rx_datain_0,                  --              pcie_ip_rx_in.rx_datain_0
			pcie_ip_test_in_test_in                    => CONNECTED_TO_pcie_ip_test_in_test_in,                    --            pcie_ip_test_in.test_in
			pcie_ip_tx_out_tx_dataout_0                => CONNECTED_TO_pcie_ip_tx_out_tx_dataout_0,                --             pcie_ip_tx_out.tx_dataout_0
			reset_reset_n                              => CONNECTED_TO_reset_reset_n                               --                      reset.reset_n
		);

