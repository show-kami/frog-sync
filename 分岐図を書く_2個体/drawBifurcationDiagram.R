data <- read.csv("output_forBifurcation.csv", header = T)

span.gamma <- c(0, 1)
span.phi <- c(0, 2*pi)

png(filename = "bifurcation.png", height = 800, width = 1000, res = 144)
plot(data$gamma, data$StableEquil_1, pch = 16, col = "black", xlim = span.gamma, ylim = span.phi, xlab = "gamma", ylab = "Phi Equilibrium Solution")
par(new=T)
plot(data$gamma, data$StableEquil_2, pch = 16, col = "black", xlim = span.gamma, ylim = span.phi, xlab = "", ylab = "")
par(new=T)
plot(data$gamma, data$UnstableEquil_1, pch = 16, col = "gray", xlim = span.gamma, ylim = span.phi, xlab = "", ylab = "")
par(new=T)
plot(data$gamma, data$UnstableEquil_2, pch = 16, col = "gray", xlim = span.gamma, ylim = span.phi, xlab = "", ylab = "")

abline(h = 0)
abline(h = pi)
abline(h = 2 * pi)

legend.names <- c("stable", "unstable")
legend.col <- c("black", "gray")
legend.pch <- c(16, 16, 16, 16)
legend("topleft", legend = legend.names, col = legend.col, pch = legend.pch)

dev.off()
