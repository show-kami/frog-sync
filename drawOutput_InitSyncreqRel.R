data.rel <- read.csv("output_InitialPhaseDiff_SyncRequiredTime_Relation.csv", header = T)

png(filename = "output_InitialPhaseDiff_SyncRequiredTime_Relation.png", height = 600, width = 1000, res = 144)
plot(data.rel$initial_phase_difference, data.rel$sync_required_time, type = "p", xlab="Initial Phase Difference", ylab = "Required Time for Sync", xaxt = "n")

axis.name.left <- c( "0", "pi/4","pi/2","3pi/4" ,"pi")
axis(1, at = seq(0,pi,by=pi/4), labels = axis.name.left)


dev.off()