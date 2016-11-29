stable <- read.csv("output_forBifurcationOfPhaseshift_stable.csv", header = F)
unstable <- read.csv("output_forBifurcationOfPhaseshift_unstable.csv", header = F)

span.r <- c(0, 15)
span.phi <- c(0, 2*pi)

png(filename = "bifurcation_Phaseshift.png", height = 800, width = 1000, res = 144)
plot(stable$V1, stable$V2, pch = 16, col = "black", 
     xlim = span.r, ylim = span.phi, yaxt = "n", xlab = "Distance between two interacting frogs [m]", ylab = "Phi Equilibrium Solution")
par(new=T)
plot(stable$V1, stable$V3, pch = 16, col = "black", 
     xlim = span.r, ylim = span.phi, yaxt = "n", xlab = "", ylab = "")
par(new=T)
plot(unstable$V1, unstable$V2, pch = 16, col = "gray", 
     xlim = span.r, ylim = span.phi, yaxt = "n", xlab = "", ylab = "")
par(new=T)
plot(unstable$V1, unstable$V3, pch = 16, col = "gray", 
     xlim = span.r, ylim = span.phi, yaxt = "n", xlab = "", ylab = "")


legend.names <- c("stable", "unstable")
legend.col <- c("black", "gray")
legend.pch <- c(16, 16)
legend("topright", legend = legend.names, col = legend.col, pch = legend.pch)

axis.name.left <- c( "0", "pi/3","2pi/3","pi", "4pi/3", "5pi/3", "2pi")
axis(1)
axis(2, at = seq(0,2*pi,by=pi/3), labels = axis.name.left)

dev.off()
