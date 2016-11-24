data.rel <- read.csv("output_GammaDphidtRel.csv", header = T)

png(filename = "output_GammaDphidtRel.png", height = 800, width = 1200, res = 144)
plot(data.rel$phi, data.rel$gamma0, type = "l", lwd=2, xlab="Phase Difference φ", ylab = "dφ/dt", xlim=c(0,2*pi), ylim=c(-4,4), col=2)
par(new=T)
plot(data.rel$phi, data.rel$gamma0.25, type = "l", lwd=2, xlab="", ylab = "", xlim=c(0,2*pi), ylim=c(-4,4), col=3)
par(new=T)
plot(data.rel$phi, data.rel$gamma0.5, type = "l", lwd=2, xlab="", ylab = "", xlim=c(0,2*pi), ylim=c(-4,4), col=4)
par(new=T)
plot(data.rel$phi, data.rel$gamma0.75, type = "l", lwd=2, xlab="", ylab = "", xlim=c(0,2*pi), ylim=c(-4,4), col=5)
par(new=T)
plot(data.rel$phi, data.rel$gamma1.0, type = "l", lwd=2, xlab="", ylab = "", xlim=c(0,2*pi), ylim=c(-4,4), col=6)

par(new=T)
abline(h=0)

legend.names <- c("gamma = 0", "gamma = 0.25", "gamma = 0.5", "gamma = 0.75", "gamma = 1.0")
legend.lwd <- c(2,2,2,2,2)
legend.col <- c(2,3,4,5,6)
legend("topright", legend=legend.names, lwd = legend.lwd, col = legend.col)

dev.off()