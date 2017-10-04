module ConexionAtomNios(
 input OSC_50_BANK2,
 input PCIE_PREST_n,
 input PCIE_REFCLK_p,
 input PCIE_RX_p,
 output PCIE_TX_p

 );


 de2i_150_pcie system_inst(
 .clk_clk (OSC_50_BANK2),
 .pcie_ip_refclk_export (PCIE_REFCLK_p),
 .reset_reset_n (1'b1),
 .pcie_ip_pcie_rstn_export (PCIE_PREST_n),
 .pcie_ip_rx_in_rx_datain_0 (PCIE_RX_p),
 .pcie_ip_tx_out_tx_dataout_0 (PCIE_TX_p)
 );
 

 
endmodule