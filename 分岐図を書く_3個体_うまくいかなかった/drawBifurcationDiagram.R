stable <- read.csv("output_forBifurcation3_stable.csv", header = T)
unstable <- read.csv("output_forBifurcation3_unstable.csv", header = T)

span.gamma <- c(0, 1)
span.phi <- c(0, 2*pi)

png(filename = "bifurcation_num3.png", height = 1600, width = 2000, res = 144)
plot(stable$gamma, stable$phi_12, pch = 16, col = "blue", xlim = span.gamma, ylim = span.phi, xlab = "gamma", ylab = "Phi Equilibrium Solution")
par(new=T)
plot(stable$gamma, stable$phi_13, pch = 16, col = "red", xlim = span.gamma, ylim = span.phi, xlab = "", ylab = "")
par(new=T)
plot(unstable$gamma, unstable$phi_12, pch = 16, col = "skyblue", xlim = span.gamma, ylim = span.phi, xlab = "", ylab = "")
par(new=T)
plot(unstable$gamma, unstable$phi_13, pch = 16, col = "pink", xlim = span.gamma, ylim = span.phi, xlab = "", ylab = "")

abline(h = 0)
abline(h = pi)
abline(h = 2 * pi)

legend.names <- c("stable (phi_12)", "stable (phi_13)", "unstable (phi_12)", "unstable (phi_13)")
legend.col <- c("blue", "red", "skyblue", "pink")
legend.pch <- c(16, 16, 16, 16)
legend("topleft", legend = legend.names, col = legend.col, pch = legend.pch)

dev.off()
