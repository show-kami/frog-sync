data.phi12 <- read.csv("output_nullcline_phi12.csv", header = T)
data.phi13 <- read.csv("output_nullcline_phi13.csv", header = T)

span <- c(0, 2*pi)

png(filename = "nullcline_num3.png", height = 2000, width = 2000, res = 144)
plot(data.phi12$phi_12, data.phi12$phi_13, pch = 20, col = "blue", xlim = span, ylim = span, xlab = "phi_12", ylab = "phi_13")
par(new=T)
plot(data.phi13$phi_12, data.phi13$phi_13, pch = 20, col = "red", xlim = span, ylim = span, xlab = "", ylab = "")

legend.names <- c("phi_12", "phi_13")
legend.col <- c("blue", "red")
legend.pch <- c(20, 20)
legend("topleft", legend = legend.names, col = legend.col, pch = legend.pch)

dev.off()
