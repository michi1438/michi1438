#
# ~/.bashrc
#

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

alias 'c'=clear
alias 'r'=reset

export CLICOLOR=1
export LSCOLORS=ExGxBxDxCxEgEdxbxgxcxd
alias l="ls -al"

alias ls='ls --color=auto'

parse_git_branch()
{
	git branch 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/ (\1)/'
}

PS1="\u@\h[\A] \[\033[32m\]\w\[\033[33m\]\$(parse_git_branch)\[\033[00m\] $ "

alias sshtower="ssh michaeltower@91.69.16.29 -p 222"
alias rmswaps="rm ~/.cache/vim/swap/*"
alias vi='vim'
alias c='clear'
alias r='reset'
alias susp='systemctl suspend'
alias norm='norminette'
