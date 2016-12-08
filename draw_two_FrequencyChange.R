data <- read.csv("output_two_DthetaDt.csv")

png(filename = "plot_two_DthetaDt.png", height = 600, width = 1000, res = 144)
plot(data$time, data$frog_A, xlab="time [s]", ylab = "angular frequency [rad/s]", ylim = c(0, 11*pi), yaxt = "n")
par(new = T)
plot(data$time, data$frog_B, xlab="time [s]", ylab = "angular frequency [rad/s]", ylim = c(0, 11*pi), yaxt = "n")
par(new = T)
plot(data$time, data$frog_A - data$frog_B, xlab="time [s]", col = "red", ylab = "angular frequency [rad/s]", ylim = c(0, 11*pi), yaxt = "n")


axis.point <- seq(0, 11*pi, by = pi)
axis.name <- c("0", "pi", "2pi", "3pi", "4pi", "5pi", "6pi", "7pi", "8pi", "9pi","10pi","11pi")
axis(2, at = axis.point, labels = axis.name)

dev.off()