library(tcltk)

data <- read.csv("output_theta.csv", header = T)
data.raster <- read.csv("output_thetaForRasterPlot.csv", header = T)

num.frogs <- 100 # 考えている個体数
t_0 <- min(data$time)
t_end <- max(data$time)
num.row <- nrow(data)

# プログレスバーの設定
if(num.frogs > 2){
	pb <- txtProgressBar(min = 1, max = num.frogs - 1, style = 3)
}

# 各個体の位相の時間変化
if (num.frogs == 2 || num.frogs == 3){
	png(filename = "plot_PhaseCurve.png", height = 600, width = 300 * (t_end - t_0), res = 144)
	plot(data$time, (data$theta_0), type = "l", col = "red", xlab="time [s]", ylab = "phase")
	if (num.frogs >= 2){
		par(new=T)
		plot(data$time, (data$theta_1), type = "l", col = "blue", xlab="", ylab = "")
	}
	if (num.frogs >= 3){
		par(new=T)
		plot(data$time, (data$theta_2), type = "l", col = "green", xlab="", ylab = "")
	}
	dev.off()
} else {
	png(filename = "plot_PhaseCurve.png", height = 600, width = 300 * (t_end - t_0), res = 144)
	plot(as.matrix(data[1]), as.matrix(data[2]), type = "l", xlab="time [s]", ylab = "phase")
	for (i in 1:num.frogs-2){
		par(new = T)
		plot(as.matrix(data[1]), as.matrix(data[i+2]), type = "l", xlab="", ylab = "")
		setTxtProgressBar(pb, i)
	}
	par(new = T)
	plot(data$time, as.matrix(data[num.frogs+1]), type = "l", col = "red", xlab="", ylab = "")
	dev.off()
}

# 各個体間の位相差の時間変化
if(num.frogs == 2 || num.frogs == 3){
	span.time <- c(t_0, t_end)
	span.phase <- c(0, 2*pi)
	png(filename = "plot_PhaseTimeChange.png", height = 1000, width = 1000, res = 144)
	if (num.frogs == 2){
		plot(data$time, data$PhaseDifference.0_1., type = "l", lty = "solid", xlab="time [s]", ylab="phase difference", xlim = span.time, ylim = span.phase, yaxt="n")
	}
	if (num.frogs == 3){
		par(new=T)
		plot(data$time, data$PhaseDifference.0_2., type = "l", lty = "dashed", xlab="", ylab="", xlim = span.time, ylim = span.phase ,yaxt="n")
		par(new=T)
		plot(data$time, data$PhaseDifference.1_2., type = "l", lty = "dotted", xlab="", ylab="", xlim = span.time, ylim = span.phase ,yaxt="n")
	}
	axis.point <- seq(0, 2*pi, by = pi/3)
	axis.name <- c("0", "pi/3", "2pi/3", "pi", "4pi/3", "5pi/6", "2pi")
	axis(2, at = axis.point, labels = axis.name)
	dev.off()
}

# ラスタープロット
png(filename = "plot_rasterplot.png", height = 300 + 20 * num.frogs, width = 300 * (t_end - t_0), res = 144)
plot(as.matrix(data.raster[1]), as.matrix(data.raster[2]), pch=15, xlim=c(t_0, t_end), ylim=c(0, num.frogs-1), xlab="time [s]", ylab="Frog No.")
for(i in 1:num.frogs-1){
	time <- as.matrix(data.raster[1])
	raster <- as.matrix(data.raster[i+2])
	par(new = T)
	plot(time, raster, pch=15, xlim=c(t_0, t_end), ylim=c(0, num.frogs-1), xlab="", ylab="")
	if(num.frogs > 2){
		setTxtProgressBar(pb, i)
	}
}
dev.off()
