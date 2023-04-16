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

#OSC-7 escape sequence to open new term in the same dir as parent term instance,
osc7_cwd() {
	local strlen=${#PWD}
	local encoded=""
	local pos c o
	for (( pos=0; pos<strlen; pos++ )); do
		c=${PWD:$pos:1}
		case "$c" in
			[-/:_.!\'\(\)~[:alnum:]] ) o="${c}" ;;
			* ) printf -v o '%%%02X' "'${c}" ;;
	     esac
		encoded+="${o}"
	done
	printf '\e]7;file://%s%s\e\\' "${HOSTNAME}" "${encoded}"
}

parse_git_branch()
{
	git branch 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/ (\1)/'
}

prompt_color='\[\033[;32m\]'
info_color='\[\033[1;34m\]'
PS1="$prompt_color┌─$info_color(\u@\h)[\A] $prompt_color[\033[0;1m\]\w$prompt_color]\[\033[33m\]\$(parse_git_branch)\[\033[00m\] \n$prompt_color└$info_color> \[\033[0m\]";
unset prompt_color
unset info_color

alias sshtower="ssh michaeltower@91.69.16.29 -p 222"
alias rmswaps="rm ~/.cache/vim/swap/*"
alias vi='vim'
alias c='clear'
alias r='reset'
alias susp='systemctl suspend'
alias norm='norminette'
