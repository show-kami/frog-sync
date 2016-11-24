num <- 3 # 考えている個体数
data <- read.csv("output_theta.csv", header = T)

# ヌルクラインを描く
# 陰関数の描き方について，参考: http://blog.goo.ne.jp/r-de-r/e/ff2399cb40043afca226208e8fefaec9
K <- 1.0
gamma <- 0.25
phi12 <- seq(0, 2*pi, length = 1000)
phi13 <- seq(0, 2*pi, length = 1000)
Dphi12Dt <- matrix(0, 1000, 1000)
Dphi13Dt <- matrix(0, 1000, 1000)
for (i in 1:1000){
	for (j in 1:1000){
		Dphi12Dt[i,j] <- 2 * K * (sin(phi12[i]) - gamma * sin(2 * phi12[i])) +  K * (sin(phi13[j]) - gamma * sin(2*phi13[j]) + sin(phi12[i]-phi13[j]) - gamma * sin(2*(phi12[i]-phi13[j])))
		Dphi13Dt[i,j] <- 2 * K * (sin(phi13[j]) - gamma * sin(2 * phi13[j])) +  K * (sin(phi12[i]) - gamma * sin(2*phi12[i]) + sin(phi13[j]-phi12[i]) - gamma * sin(2*(phi13[j]-phi12[i])))
	}
}
span.phi12 <- c(0,2*pi)
span.phi13 <- c(0,2*pi)
png(filename = "plot_PhasePlane.png", height = 1000, width = 1000, res = 144)
contour(phi12, phi13, Dphi12Dt, drawlabels = FALSE, levels = 0, col = "red", xlab = "Phase Difference between Frog1 and Frog2", ylab = "Phase Difference between Frog1 and Frog3", xlim = span.phi12, ylim = span.phi13, xaxp = c(span.phi12, 6), yaxp = c(span.phi13, 6))
par(new=T)
contour(phi12, phi13, Dphi13Dt, drawlabels = FALSE, levels = 0, col = "blue", xlab = "", ylab = "", xlim = span.phi12, ylim = span.phi13, xaxp = c(span.phi12, 6), yaxp = c(span.phi13, 6))

# 相平面
if (num >= 3){
	par(new=T)
	plot(data$PhaseDifference.1_2., data$PhaseDifference.1_3., type = "l", lwd = 2, xlab = "", ylab = "", xlim = span.phi12, ylim = span.phi13, xaxp = c(span.phi12, 6), yaxp = c(span.phi13, 6))
}
legend.names <- c("trajectory", "nullcline (phi_12)", "nullcline (phi_13)")
legend.lwd <- c(2,1,1)
legend.col <- c("black", "red", "blue")
legend("topright", legend = legend.names, lwd = legend.lwd, col = legend.col)
dev.off()
