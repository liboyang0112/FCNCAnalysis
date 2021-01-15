import os,subprocess

# constant 
current_cut=5
current_tree=10
cut_step=5
tree_step=10

# obtain the BDT optimise score
def getScore(out):
    for line in out:
        #print "in getScore:"+line
        if "optmisationScore" in line:
            score=line.strip().split(":")[-1]
    return score



def runTrainBDT(current_cut_tmp,current_tree_tmp):#5,10
    command_cut_direction  ="trainBDT_run reg2mtau1b3jos 2 "+str(current_cut_tmp+cut_step)+" "+str(current_tree_tmp)+"  |grep optmisationScore"
    command_tree_direction ="trainBDT_run reg2mtau1b3jos 2 "+str(current_cut_tmp)+" "+str(current_tree_tmp+tree_step)+"  |grep optmisationScore"
    #print command_cut_direction+"\n"
    #print command_tree_direction+"\n"
    cut_direction_result=subprocess.Popen(command_cut_direction, shell=True, stdout=subprocess.PIPE)
    tree_direction_result=subprocess.Popen(command_tree_direction, shell=True, stdout=subprocess.PIPE)
    score_cut_direction=getScore(cut_direction_result.stdout.readlines())
    score_tree_direction=getScore(tree_direction_result.stdout.readlines())
    print "cut:"+str(current_cut_tmp+cut_step)+",tree:"+str(current_tree_tmp)+",score:"+str(score_cut_direction)
    print "cut:"+str(current_cut_tmp)+",tree:"+str(current_tree_tmp+tree_step)+",score:"+str(score_tree_direction)
    return score_cut_direction,score_tree_direction

def printLog(current_cut_,current_tree_,score_current_):
    print "current cut:"+str(current_cut_)+",current tree:"+str(current_tree_)+",score_current:"+str(score_current_)

p = subprocess.Popen("trainBDT_run reg2mtau1b3jos 2  5  10 |grep optmisationScore", shell=True, stdout=subprocess.PIPE)
out = p.stdout.readlines()
score_current=getScore(out)
print "initial score:"+str(score_current)

while True:
    score_cut_direction,score_tree_direction=runTrainBDT(current_cut,current_tree)# 5,10
    if score_current>=score_cut_direction and score_current>=score_tree_direction:
        print "maximum result:"
        printLog(current_cut,current_tree,score_current)
        break
    if score_cut_direction>score_tree_direction:
        current_cut+=cut_step
        score_current=score_cut_direction
        #printLog(current_cut,current_tree,score_current)
    else:
        current_tree+=tree_step
        score_current=score_tree_direction
        #printLog(current_cut,current_tree,score_current)